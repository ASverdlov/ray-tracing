#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "ray-tracing/bitmap.hpp"
#include "ray-tracing/resolution.hpp"

namespace rt {

class Image {
 public:
  void Draw(const Bitmap& bitmap) const;
  void SetResolution(const Resolution& resolution);
  void SetResolution(float width, float height);
  size_t Width() const;
  size_t Height() const;

 private:
  Resolution resolution_;
};

}  // namespace rt

#endif
