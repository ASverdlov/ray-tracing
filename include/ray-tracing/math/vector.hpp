#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

namespace rt {

struct Vector {
  Vector()
    : x(0), y(0), z(0)
  {}
  Vector(const Vector& rhs)
    : x(rhs.x), y(rhs.y), z(rhs.z)
  {}
  Vector(double x, double y, double z)
    : x(x), y(y), z(z)
  {}

  bool IsNear(const Vector& other, double accuracy = 1e-9) const {
    return (x - other.x) <= accuracy && (y - other.y) <= accuracy && (z - other.z) <= accuracy;
  }

  // Basic operations
  Vector operator-() const {
    return Vector(-x, -y, -z);
  }
  Vector operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
  }
  Vector operator-(const Vector& other) const {
    return Vector(x - other.x, y - other.y, z - other.z);
  }
  Vector operator*(double koefficient) const {
    return Vector(x * koefficient, y * koefficient, z * koefficient);
  }
  Vector operator/(double koefficient) const {
    return Vector(x / koefficient, y / koefficient, z / koefficient);
  }

  Vector& operator+=(const Vector& other) {
    *this = *this + other;
    return *this;
  }
  Vector& operator-=(const Vector& other) {
    *this = *this - other;
    return *this;
  }
  Vector& operator*=(double koefficient) {
    *this = *this * koefficient;
    return *this;
  }
  Vector& operator/=(double koefficient) {
    *this = *this / koefficient;
    return *this;
  }

  // Comparison operators
  bool operator==(const Vector& other) const {
    return x == other.x && y == other.y && z == other.z;
  }
  bool operator!=(const Vector& other) const {
    return !(*this == other);
  }

  // Scalar product
  double operator*(const Vector& other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  // Cross product
  Vector operator%(const Vector& other) const {
    return Vector(y * other.z - other.y * z,
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

}  // namespace rt

#endif
