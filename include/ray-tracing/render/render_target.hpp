#ifndef RENDER_TARGET_HPP
#define RENDER_TARGET_HPP

#include "ray-tracing/render/bitmap.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class RenderTarget {
 public:
  virtual void Draw(const Bitmap& bitmap) const = 0;
  virtual void SetResolution(const Resolution& resolution);
  virtual void SetResolution(float width, float height);
  virtual size_t Width() const;
  virtual size_t Height() const;

 protected:
  Resolution resolution_;
};

}  // namespace rt

#endif
