#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "ray-tracing/collision.hpp"
#include "ray-tracing/color.hpp"
#include "ray-tracing/macroses.hpp"

#include <vector>

namespace rt {
class Ray;
class Vector;
class Scene;
class Image;
}

namespace rt {

class Renderer {
 public:
  Renderer(Scene* scene, Image* image)
    : scene_(scene)
    , image_(image)
  {
  }

 public:
  void Render();

 private:
  Color RenderPixel(double x, double y) const;

  Color PhongLight(const Collision& on_surface_hit, const Vector& camera_direction) const;

  Collision FindClosestCollision(const Ray& ray) const;

 private:
  DISABLE_COPYING(Renderer);

  Scene* scene_;
  Image* image_;
};

}  // namespace rt

#endif
