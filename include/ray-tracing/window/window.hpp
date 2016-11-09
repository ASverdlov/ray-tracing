#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "ray-tracing/render/frame.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Window {
 public:
  Window() {}
  Window(int width, int height) : resolution_(width, height) {}
  explicit Window(const Resolution& resolution) : resolution_(resolution) {}

  void SetResolution(int width, int height) {
    resolution_ = Resolution(width, height);
  }
  void SetResolution(const Resolution& resolution) {
    resolution_ = resolution;
  }
  Resolution GetResolution() const { return resolution_; }

  void Show(const Frame& frame);

 private:
  Resolution resolution_;
};

}  // namespace rt

#endif
