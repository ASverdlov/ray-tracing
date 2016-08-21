#ifndef RAY_HPP
#define RAY_HPP

#include "ray-tracing/geometry/vector.hpp"

namespace rt {

class Ray {
 public:
  Ray() {}
  Ray(const Vector& origin, const Vector& direction)
    : origin_(origin), direction_(direction)
  {}

  Vector GetOrigin() const { return origin_; }
  Vector GetDirection() const { return direction_; }

 private:
  Vector origin_;
  Vector direction_;
};

}  // namespace rt

#endif
