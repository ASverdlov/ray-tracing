#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "ray-tracing/render/bitmap.hpp"
#include "ray-tracing/render/render_target.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Image : public RenderTarget {
 public:
  virtual void Draw(const Bitmap& bitmap) const;
};

}  // namespace rt

#endif
