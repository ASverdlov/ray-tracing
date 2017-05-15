#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "ray-tracing/math/ray.hpp"
#include "ray-tracing/math/vector.hpp"

#include "ray-tracing/color.hpp"
#include "ray-tracing/scene.hpp"
#include "ray-tracing/image.hpp"
#include "ray-tracing/macroses.hpp"

#include <vector>

namespace rt {

class Renderer {
 public:
  Renderer() {}

  void Render(Scene* scene, const Image* target);

 private:
  Color RenderPixel(double x, double y) const;
  Collision FindClosestCollision(const Ray& ray) const;
  double GetBrightness(Vector position) const;
  static double CalculateBrightness(double cosine, double distance);

  Scene* scene_;

  DISABLE_COPYING(Renderer);
};

}  // namespace rt

#endif
