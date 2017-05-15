#include "ray-tracing/image.hpp"

#include "ray-tracing/bitmap.hpp"

#include <Magick++.h>

namespace rt {

void Image::Draw(const Bitmap& bitmap) const {
  ::Magick::Geometry geometry(bitmap.Width(), bitmap.Height());
  Magick::Image image(geometry, "black");

  for (size_t x = 0; x < bitmap.Width(); ++x) {
    for (size_t y = 0; y < bitmap.Height(); ++y) {
      auto color = Magick::Color((64 * 1024 - 1) * bitmap(x, y).r,
                                 (64 * 1024 - 1) * bitmap(x, y).g,
                                 (64 * 1024 - 1) * bitmap(x, y).b);
      image.pixelColor(x, y, color);
    }
  }
  image.write("rendered_picture.png");
}

void Image::SetResolution(const Resolution& resolution) {
  resolution_ = resolution;
}

void Image::SetResolution(float width, float height) {
  resolution_ = Resolution(width, height);
}

size_t Image::Width() const {
  return resolution_.width;
}

size_t Image::Height() const {
  return resolution_.height;
}

}  // namespace rt
