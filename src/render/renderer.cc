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
  return 70.0 * fabs(cosinus) / distance * 70. / distance;
}

double Renderer::GetBrightness(Vector position) const {
  double total_brightness = scene_->GetAmbientLight();
  total_brightness = .1;
  for (const auto* light : scene_->GetLights()) {
    Ray light_ray(light->GetPosition(), position - light->GetPosition());
    auto light_collision = FindClosestCollision(light_ray);
    if (light_collision.touching.IsNear(position)) {
      double add = CalculateBrightness(light_collision.cosinus,
                                       light_collision.trace_distance);
      total_brightness += add;
      std::cout << "Light reaches it: " << add << "\n";
    }
  }
  return total_brightness;
}

Color Renderer::RenderPixel(double x, double y) const {
  auto camera_ray = scene_->GetCamera()->GetRay(x, y);
  auto collision = FindClosestCollision(camera_ray);
  if (!collision.Exists())
    return Color::black;
  double brightness = GetBrightness(collision.touching);
  return collision.color.ApplyBrightness(brightness);
}

void Renderer::Render(Scene* scene, const RenderTarget* target) {
  scene_ = scene;
  size_t width = target->Width();
  size_t height = target->Height();
  Bitmap bitmap(width, height);
  for (size_t x = 0; x < width; ++x)
    for (size_t y = 0; y < height; ++y)
      bitmap(x, y) = RenderPixel(static_cast<float>(x) / width,
                                 static_cast<float>(y) / height);
  target->Draw(bitmap);
}

}  // namespace rt
