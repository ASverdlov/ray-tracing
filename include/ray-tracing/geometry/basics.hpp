#ifndef BASICS_HPP
#define BASICS_HPP

#include <cmath>

#include <point.hpp>
#include <utils.hpp>

namespace rt {

struct Vec3d {
  Vec3d() {}
  Vec3d(double x, double y, double z)
    : x(x), y(y), z(z)
  {}

  // Basic operations
  Vec3d& operator=(const Vec3d& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
  }
  Vec3d operator+(const Vec3d& other) const {
    return Vec3d(x + other.x, y + other.y, z + other.z);
  }
  Vec3d operator-(const Vec3d& other) const {
    return Vec3d(x - other.y, y - other.y, z - other.z);
  }
  Vec3d& operator+=(const Vec3d& other) {
    *this = *this + other;
  }
  Vec3d& operator-=(const Vec3d& other) {
    *this = *this - other;
  }
  
  // Comparison operators
  bool operator==(const Vec3d& other) const {
    return x == other.x && y == other.y && z == other.z;
  }
  bool operator!=(const Vec3d& other) const {
    return !(*this == other);
  }

  // Scalar product
  double operator*(const Vec3d& other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  // Cross product
  Vec3d operator%(const Vec3d&) const {
    return Vec3d(y * other.z - other.y * z,
                 x * other.z - other.x * z,
                 x * other.y - other.x * y);
  }

  // Length
  double GetLength() const {
    return sqrt(x * x + y * y + z * z);
  }

  // Data
  double x, y, z;
};


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

} // namespace rt

#endif
