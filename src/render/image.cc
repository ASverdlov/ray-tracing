#include <Magick++.h>

#include "ray-tracing/render/image.hpp"
#include "ray-tracing/render/frame.hpp"

namespace rt {

void Image::Draw(const Frame& frame) const {
  Magick::Image image(Magick::Geometry(frame.Width(), frame.Height()), "white");
  for (size_t x = 0; x < frame.Width(); ++x) {
    for (size_t y = 0; y < frame.Height(); ++y) {
      image.pixelColor(x, y, Magick::Color(65000 * frame(y, x).r,
                                           65000 * frame(y, x).g,
                                           65000 * frame(y, x).b));
    }
  }
  image.write("rendered_picture.png");
}

}  // namespace rt
