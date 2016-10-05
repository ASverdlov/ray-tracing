#include "ray-tracing/render/renderer.hpp"

#include <cmath>

namespace rt {

Collision Renderer::FindClosestCollision(const Ray& ray) {
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
  return 1.0 * fabs(cosinus) / power(distance, 2.0);
}

double Renderer::GetBrightness(Vector position) {
  double total_brightness = scene_->GetAmbientLight();
  for (const auto* light : scene_->GetLights()) {
    Ray light_ray(light.GetPosition(), position - light.GetPosition());
    auto light_collision = FindClosestCollision(light_ray);

    if (light_collision.touching == position) {
      total_brightness += CalculateBrightness(light_collision.cosinus,
                                              light_collision.trace_distance);
    }
  }
  return total_brightness;
}

Color Renderer::RenderPixel(size_t x, size_t y) const {
  auto camera_ray = scene_->GetCamera()->GetRay(x, y);
  auto collision = FindClosestCollision(camera_ray);

  if (!collision.Exists()) {
    return Color::black;
  }
  double brightness = GetBrightness(collision.touching);
  return collision.color.ApplyBrightness(brightness);
}

Frame Renderer::RenderScene(Scene* scene, const Resolution& resolution) {
  scene_ = scene;
  size_t height = resolution.height;
  size_t width = resolution.width;

  Frame bitmap(width * height * 3, 0);
  for (size_t x = 0; x < width; ++x) {
    for (size_t y = 0; y < height; ++y) {
      Color pixel_color = RenderPixel(x, y);
      bitmap[y * width * 3 + x * 3 + 0] = pixel_color.r;
      bitmap[y * width * 3 + x * 3 + 1] = pixel_color.g;
      bitmap[y * width * 3 + x * 3 + 2] = pixel_color.b;
    }
  }
  return bitmap;
}

}  // namespace rt
