#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include "ray-tracing/render/frame.hpp"
#include "ray-tracing/render/color.hpp"
#include "ray-tracing/scene/scene.hpp"
#include "ray-tracing/render/render_target.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Renderer {
 public:
  Renderer() {}

  void Render(Scene* scene, const RenderTarget* target);

 private:
  Color RenderPixel(double x, double y) const;
  Collision FindClosestCollision(const Ray& ray) const;
  double GetBrightness(Vector position) const;
  static double CalculateBrightness(double cosinus, double distance);

  Scene* scene_;

  DISABLE_COPYING(Renderer);
};

}  // namespace rt

#endif
