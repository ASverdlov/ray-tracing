#ifndef LINE_HPP
#define LINE_HPP

#include <vec.hpp>

class Line {
 public:
  Line() {}
  Line(const Vec3d& origin, const Vec3d& direction)
    : origin_(origin), direction_(direction)
  {}

  Vec3d GetOrigin() const { return origin_ };
  Vec3d GetDirection() const { return direction_ };

 private:
  Vec3d origin_;
  Vec3d direction_;
};

#endif
