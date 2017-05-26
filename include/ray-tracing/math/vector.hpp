#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

namespace rt {

class Vector {
 public:
  Vector()
    : x(0), y(0), z(0)
  {}

  Vector(const Vector& rhs)
    : x(rhs.x), y(rhs.y), z(rhs.z)
  {}

  Vector(double x, double y, double z)
    : x(x), y(y), z(z)
  {}

 public:
  bool IsNear(const Vector& other, double accuracy = 1e-9) const {
    return fabs(x - other.x) <= accuracy && fabs(y - other.y) <= accuracy && fabs(z - other.z) <= accuracy;
  }

  Vector Normalize() const {
    double k = Length();
    return Vector(x / k, y / k, z / k);
  }

  // Length
  double Length() const {
    return sqrt(x * x + y * y + z * z);
  }

 public:
  double x, y, z;
};

/* vector-double operations */
Vector operator*(const Vector& a, double k);

Vector operator*(double k, const Vector& a);

Vector operator/(const Vector& a, double k);

/* vector-vector operations */
Vector operator+(const Vector& a, const Vector& b);

Vector operator-(const Vector& a, const Vector& b);


/* Comparison operators */
bool operator==(const Vector& a, const Vector& b);

bool operator!=(const Vector& a, const Vector& b);


/* Dot product */
double operator*(const Vector& a, const Vector& b);

/* Cross product */
Vector operator%(const Vector& a, const Vector& b);

/* Self operations */
Vector operator-(const Vector& a);

Vector& operator+=(Vector& a, const Vector& b);

Vector& operator-=(Vector& a, const Vector& b);

Vector& operator*=(Vector& a, double k);

Vector& operator/=(Vector& a, double k);

}  // namespace rt

#endif
