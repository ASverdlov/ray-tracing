#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "ray-tracing/render/frame.hpp"
#include "ray-tracing/render/render_target.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Image : public RenderTarget {
 public:
  virtual void Draw(const Frame& frame) const;
};

}  // namespace rt

#endif
