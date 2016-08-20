#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <frame.hpp>
#include <scene.hpp>
#include <window.hpp>
#include <color.hpp>
#include <utility.hpp>

#include <vector>

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
