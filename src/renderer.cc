#include "ray-tracing/renderer.hpp"

#include "ray-tracing/math/ray.hpp"
#include "ray-tracing/math/vector.hpp"

#include "ray-tracing/color.hpp"
#include "ray-tracing/image.hpp"
#include "ray-tracing/scene.hpp"
#include "ray-tracing/bitmap.hpp"

#include <cmath>

namespace rt {

Collision Renderer::FindClosestCollision(const Ray& ray) const {
  Collision nearest_collision;
  for (const auto* model : scene_->Models()) {
    auto collision = model->Trace(ray);
    if (collision.Exists() && collision.IsCloserThan(nearest_collision)) {
      nearest_collision = collision;
    }
  }
  return nearest_collision;
}

// Brightness of light is in proportion to cosinus and
// inversely to distance ^ 2
double Renderer::CalculateBrightness(double cosine, double distance) {
  static constexpr double BRIGHTNESS_BASE = 5000.;
  return BRIGHTNESS_BASE * fabs(cosine) / distance / distance;
}

double Renderer::GetBrightness(Vector position) const {
  double total_brightness = scene_->GetAmbientLight();
  total_brightness = .1;
  for (const auto* light : scene_->Lights()) {
    Ray light_ray(light->GetPosition(), position - light->GetPosition());
    auto light_collision = FindClosestCollision(light_ray);
    if (light_collision.touching.IsNear(position)) {
      double add = CalculateBrightness(light_collision.cosine,
                                       light_collision.trace_distance);
      total_brightness += add;
    }
  }
  return total_brightness;
}

Color Renderer::RenderPixel(double x, double y) const {
  auto camera_ray = scene_->GetCamera()->GetRay(x, y);
  auto collision = FindClosestCollision(camera_ray);
  if (!collision.Exists())
    return BLACK;
  double brightness = GetBrightness(collision.touching);
  return collision.color.ApplyBrightness(brightness);
}

void Renderer::Render(Scene* scene, const Image* image) {
  scene_ = scene;
  size_t width = image->Width();
  size_t height = image->Height();
  Bitmap bitmap(width, height);

  for (size_t x = 0; x < width; ++x)
  for (size_t y = 0; y < height; ++y) {
    bitmap(x, y) = BLACK;

    /* Supersampling with 4 points around (x, y) */
    for (float dx = -.5; dx <= .5; ++dx)
    for (float dy = -.5; dy <= .5; ++dy)
      bitmap(x, y) += RenderPixel((static_cast<float>(x) + dx) / width,
                                  (static_cast<float>(y) + dy) / height);
    bitmap(x, y) *= .25;
  }
  image->Draw(bitmap);
}

}  // namespace rt
