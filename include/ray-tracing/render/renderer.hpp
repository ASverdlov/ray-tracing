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
  Frame RenderScene(Scene* scene, const Resolution& resolution);

 private:
  Color RenderPixel(size_t x, size_t y) const;
  Scene* scene_;

  DISABLE_COPYING(Renderer);
};

}  // namespace rt

#endif
