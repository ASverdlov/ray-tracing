#include "ray-tracing/render/render_target.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

void RenderTarget::SetResolution(const Resolution& resolution) {
  resolution_ = resolution;
}

void RenderTarget::SetResolution(float width, float height) {
  resolution_ = Resolution(width, height);
}

size_t RenderTarget::Width() const {
  return resolution_.width;
}

size_t RenderTarget::Height() const {
  return resolution_.height;
}

}  // namespace rt
