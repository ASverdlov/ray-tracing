#include "ray-tracing/render/renderer.hpp"

#include <cmath>

namespace rt {

Collision Renderer::FindClosestCollision(const Ray& ray) const {
  Collision nearest_collision;
  for (const auto* model : scene_->GetModels()) {
    auto collision = model->Trace(ray);
    if (collision.Exists() && collision.IsCloserThan(nearest_collision)) {
      nearest_collision = collision;
    }
  }
  return nearest_collision;
}

// Brightness of light is in proportion to cosinus and
// inversely to distance ^ 2
double Renderer::CalculateBrightness(double cosinus, double distance) {
  return 1.0 * fabs(cosinus) / std::pow(distance, 2.0);
}

double Renderer::GetBrightness(Vector position) const {
  double total_brightness = scene_->GetAmbientLight();
  for (const auto* light : scene_->GetLights()) {
    Ray light_ray(light->GetPosition(), position - light->GetPosition());
    auto light_collision = FindClosestCollision(light_ray);

    if (light_collision.touching == position) {
      total_brightness += CalculateBrightness(light_collision.cosinus,
                                              light_collision.trace_distance);
    }
  }
  return total_brightness;
}

Color Renderer::RenderPixel(double x, double y) const {
  auto camera_ray = scene_->GetCamera()->GetRay(x, y);
  auto collision = FindClosestCollision(camera_ray);

  if (!collision.Exists()) {
    return Color::black;
  }

  double brightness = GetBrightness(collision.touching);
  return collision.color.ApplyBrightness(brightness);
}

void Renderer::Render(Scene* scene, const RenderTarget* target) {
  scene_ = scene;

  size_t width = target->Width();
  size_t height = target->Height();

  Bitmap bitmap(width, height);
  for (size_t x = 0; x < height; ++x) {
    for (size_t y = 0; y < width; ++y) {
      bitmap(y, x) = RenderPixel(static_cast<float>(x) / height,
                                 static_cast<float>(y) / width);
    }
  }
  target->Draw(bitmap);
}

}  // namespace rt
