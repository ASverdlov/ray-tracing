#include "ray-tracing/math/vector.hpp"

namespace rt {
/* vector-double operations */
Vector operator*(const Vector& a, double k) {
  return Vector(k * a.x, k * a.y, k * a.z);
}

Vector operator*(double k, const Vector& a) {
  return Vector(k * a.x, k * a.y, k * a.z);
}

Vector operator/(const Vector& a, double k) {
  return Vector(a.x / k, a.y / k, a.z / k);
}

/* vector-vector operations */
Vector operator+(const Vector& a, const Vector& b) {
  return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector& a, const Vector& b) {
  return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}


/* Comparison operators */
bool operator==(const Vector& a, const Vector& b) {
  return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const Vector& a, const Vector& b) {
  return !(a == b);
}


/* Dot product */
double operator*(const Vector& a, const Vector& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

/* Cross product */
Vector operator%(const Vector& a, const Vector& b) {
  return Vector(a.y * b.z - b.y * a.z,
                a.x * b.z - b.x * a.z,
                a.x * b.y - b.x * a.y);
}

/* Self operations */
Vector operator-(const Vector& a) {
  return Vector(-a.x, -a.y, -a.z);
}

Vector& operator+=(Vector& a, const Vector& b) {
  a = a + b;
  return a;
}

Vector& operator-=(Vector& a, const Vector& b) {
  a = a - b;
  return a;
}

Vector& operator*=(Vector& a, double k) {
  a = a * k;
  return a;
}

Vector& operator/=(Vector& a, double k) {
  a = a / k;
  return a;
}

}  // namespace rt
