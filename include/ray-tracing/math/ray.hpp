#ifndef RAY_HPP
#define RAY_HPP

#include "ray-tracing/math/vector.hpp"

namespace rt {

class Ray {
 public:
  Ray() {}
  Ray(const Vector& origin, const Vector& direction)
    : origin_(origin), direction_(direction)
  {}

  Vector Origin() const { return origin_; }
  Vector Direction() const { return direction_; }

 private:
  Vector origin_;
  Vector direction_;
};

}  // namespace rt

#endif
