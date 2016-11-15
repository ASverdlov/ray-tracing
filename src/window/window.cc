#include <Magick++.h>

#include "ray-tracing/window/window.hpp"
#include "ray-tracing/render/frame.hpp"

namespace rt {

void Window::Show(const Frame& frame) {
  Magick::Image image(Magick::Geometry(resolution_.width, resolution_.height),
                      "white");
  for (size_t x = 0; x < resolution_.width; ++x)
    for (size_t y = 0; y < resolution_.height; ++y)
      image.pixelColor(x, y,
                       Magick::Color(
                         65000 * frame[y * resolution_.height + x].r,
                         65000 * frame[y * resolution_.height + x].g,
                         65000 * frame[y * resolution_.height + x].b));
  image.write("rendered_picture.png");
}

}  // namespace rt
