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
    if (!collision.IsEmpty() && collision.IsCloserThan(nearest_collision)) {
      nearest_collision = collision;
    }
  }
  return nearest_collision;
}

static constexpr double PHONG_AMBIENT_LIGHT_WEIGHT = .1;
static constexpr double PHONG_DIFFUSION_LIGHT_WEIGHT = .6;
static constexpr double PHONG_SPECULAR_LIGHT_WEIGHT = .3;

static double DiffusionIntensity(const Collision& light_hit) {
  return fabs(light_hit.cosine);
}

static double SpecularIntensity(const Vector& normal, const Vector& light_direction, const Vector& camera_direction) {
  auto reflected_light = 2. * normal.Normalize() + light_direction.Normalize();
  return fmax(0., reflected_light * -camera_direction);
}

Color Renderer::PhongLight(const Collision& on_surface_hit, const Vector& camera_direction) const {
  double diffusion_intensity = 0.;
  double specular_intensity = 0.;
  for (const auto* light : scene_->Lights()) {
    Ray light_to_surface(light->Position(),
                         on_surface_hit.touching - light->Position());
    auto light_hit = FindClosestCollision(light_to_surface);

    bool light_is_not_blocked = light_hit.IsNear(on_surface_hit);
    if (light_is_not_blocked) {
      diffusion_intensity += DiffusionIntensity(light_hit);

      auto light_direction = light_to_surface.Direction();
      auto normal = light_hit.normal;
      specular_intensity += SpecularIntensity(normal, light_direction, camera_direction);
    }
  }
  if (specular_intensity != 0.)
    std::cout << "Specular intensity is not 0.\n";

  auto diffusion_light = diffusion_intensity * on_surface_hit.color;
  auto specular_light = specular_intensity * WHITE;
  auto ambient_light = scene_->AmbientLight() * on_surface_hit.color;

  return PHONG_AMBIENT_LIGHT_WEIGHT * ambient_light
         + PHONG_DIFFUSION_LIGHT_WEIGHT * diffusion_light
         + PHONG_SPECULAR_LIGHT_WEIGHT * specular_light;
}

Color Renderer::RenderPixel(double x, double y) const {
  auto camera_ray = scene_->Camera()->ViewRay(x, y);
  auto hit = FindClosestCollision(camera_ray);
  if (hit.IsEmpty())
    return BLACK;
  else
    return PhongLight(hit, camera_ray.Direction());
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
    for (float dx = -.5; dx <= .5; dx += 1.)
    for (float dy = -.5; dy <= .5; dy += 1.)
      bitmap(x, y) += RenderPixel((static_cast<float>(x) + dx) / width,
                                  (static_cast<float>(y) + dy) / height);
    bitmap(x, y) *= .25;
  }
  image->Draw(bitmap);
}

}  // namespace rt
