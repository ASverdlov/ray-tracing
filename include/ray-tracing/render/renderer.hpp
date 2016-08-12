#ifndef MAIN_DISPLAYER_HPP
#define MAIN_DISPLAYER_HPP

#include <renderer.hpp>
#include <scene.hpp>
#include <camera.hpp>
#include <utility.hpp>

namespace rt {

class Renderer {
 public:
  virtual ~Renderer() {};
  virtual Run() = 0;
};

// Default implementation, that uses OpenGL to render graphics
class DefaultRenderer : public Renderer {
 public:
  explicit DefaultRenderer(unique_ptr<Scene> scene, unique_ptr<Camera> camera)
    : scene_(std::move(scene)), camera_(std::move(camera))
  {}

  void Run() override;

 private:
  Color GetPixelColor(size_t x, size_t y) const;

  unique_ptr<Scene> scene_;
  unique_ptr<Camera> camera_;

  DISABLE_COPYING(MainDisplayer);
};

} // namespace rt

#endif
