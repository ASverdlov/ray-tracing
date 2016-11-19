#include <Magick++.h>

#include "ray-tracing/render/image.hpp"
#include "ray-tracing/render/bitmap.hpp"

namespace rt {

void Image::Draw(const Bitmap& bitmap) const {
  Magick::Image image(Magick::Geometry(bitmap.Width(), bitmap.Height()), "white");
  for (size_t x = 0; x < bitmap.Width(); ++x) {
    for (size_t y = 0; y < bitmap.Height(); ++y) {
      image.pixelColor(x, y, Magick::Color(65000 * bitmap(y, x).r,
                                           65000 * bitmap(y, x).g,
                                           65000 * bitmap(y, x).b));
    }
  }
  image.write("rendered_picture.png");
}

}  // namespace rt
