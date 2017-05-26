#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "ray-tracing/resolution.hpp"

#include <cstring>

namespace rt {
class Bitmap;
}

namespace rt {

class Image {
 public:
  void Draw(const Bitmap& bitmap) const;
  void SetResolution(const Resolution& resolution);
  void SetResolution(size_t width, size_t height);
  size_t Width() const;
  size_t Height() const;

 private:
  Resolution resolution_;
};

}  // namespace rt

#endif
