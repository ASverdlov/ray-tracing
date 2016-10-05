#include "ray-tracing/geometry/models/triangle.hpp"
#include "ray-tracing/geometry/vector.hpp"

namespace rt {

void Triangle::SetVertices(const Vector& v1,
                           const Vector& v2,
                           const Vector& v3) {
  vertices[0] = v1;
  vertices[1] = v2;
  vertices[2] = v3;
}

void Triangle::SetVertices(double x1, double y1, double z1,
                           double x2, double y2, double z2,
                           double x3, double y3, double z3) {
  vertices[0] = Vector(x1, y1, z1);
  vertices[1] = Vector(x2, y2, z2);
  vertices[2] = Vector(x3, y3, z3);
}

}  // namespace rt
