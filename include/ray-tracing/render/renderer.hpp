#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include "ray-tracing/render/frame.hpp"
#include "ray-tracing/render/color.hpp"
#include "ray-tracing/scene/scene.hpp"
#include "ray-tracing/window/window.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Renderer {
 public:
  Renderer() { }

  Frame RenderScene(Scene* scene, const Resolution& resolution);

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
