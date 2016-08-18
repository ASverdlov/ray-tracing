#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

#include <renderer.hpp>
#include <scene.hpp>
#include <color.hpp>
#include <utility.hpp>

namespace rt {

typedef std::vector<float> Frame;

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
