#include "ray-tracing/render/image.hpp"
#include "ray-tracing/render/bitmap.hpp"
#include <Magick++.h>

namespace rt {

void Image::Draw(const Bitmap& bitmap) const {
  Magick::Image image(Magick::Geometry(bitmap.Width(), bitmap.Height()),
                      "black");
  for (size_t x = 0; x < bitmap.Width(); ++x) {
    for (size_t y = 0; y < bitmap.Height(); ++y) {
      image.pixelColor(x, y, Magick::Color(65000 * bitmap(x, y).r,
                                           65000 * bitmap(x, y).g,
                                           65000 * bitmap(x, y).b));
    }
  }
  image.write("rendered_picture.png");
}

}  // namespace rt
