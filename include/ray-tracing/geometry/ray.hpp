#ifndef LINE_HPP
#define LINE_HPP

#include <vector.hpp>

class Ray {
 public:
  Ray() {}
  Ray(const Vector& origin, const Vector& direction)
    : origin_(origin), direction_(direction)
  {}

  Vector GetOrigin() const { return origin_ };
  Vector GetDirection() const { return direction_ };

 private:
  Vector origin_;
  Vector direction_;
};

#endif
