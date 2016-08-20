#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include "render/frame.hpp"
#include "render/color.hpp"
#include "scene/scene.hpp"
#include "window/window.hpp"
#include "utility.hpp"

namespace rt {

class Renderer {
 public:
  Frame RenderScene(Scene* scene, Resolution* resolution);

 private:
  Color RenderPixel(size_t x, size_t y) const;

  Scene* scene_;
  Resolution* resolution_;

  DISABLE_COPYING(Renderer);
};

}  // namespace rt

#endif
