#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include <frame.hpp>
#include <scene.hpp>
#include <window.hpp>
#include <color.hpp>
#include <utility.hpp>

namespace rt {

class Renderer {
 public:
  Frame RenderScene(Scene* scene, Resolution* resolution);

 private:
  Color RenderPixel(size_t x, size_t y) const;

  Scene* scene;
  Resolution* resolution;

  DISABLE_COPYING(Renderer);
};

} // namespace rt

#endif
