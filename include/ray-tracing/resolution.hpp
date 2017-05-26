#ifndef RESOLUTION_HPP
#define RESOLUTION_HPP

#include <cstring>

namespace rt {

struct Resolution {
  Resolution() {}
  Resolution(size_t width, size_t height) : width(width), height(height) {}

  size_t width;
  size_t height;
};

}  // namespace rt

#endif
