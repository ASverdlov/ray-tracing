#include "ray-tracing/models/triangle.hpp"

#include "ray-tracing/math/vector.hpp"

namespace rt {

Collision Triangle::Trace(const Ray& ray) const {
  /* Project ray on plane */
  auto norm = (v2 - v1) % (v3 - v1);
  double t = (v1 * norm - ray.Origin() * norm) / (ray.Direction() * norm);
  auto hit_on_plane = ray.Origin() + ray.Direction() * t;

  /* Check if it's inside our triangle */
  auto GetSign = [](double x) {
    return fabs(x) < 1e-9 ? 0 : (x < 0. ? -1 : 1);
  };
  int v12_sign = GetSign((v2 - v1) * (v1 - hit_on_plane));
  int v23_sign = GetSign((v3 - v2) * (v2 - hit_on_plane));
  int v31_sign = GetSign((v1 - v3) * (v3 - hit_on_plane));
  bool hit_is_inside_triangle = v12_sign == v23_sign && v23_sign == v31_sign;

  if (hit_is_inside_triangle) {
    Collision collision;
    collision.trace_distance = t * ray.Direction().Length();
    collision.touching = hit_on_plane;
    collision.cosine = ray.Direction() * norm / ray.Direction().Length() / norm.Length();
    collision.color = Color();
    return collision;
  } else {
    return Collision(); // no collision
  }
}

void Triangle::SetVertices(const Vector& vertex1,
                           const Vector& vertex2,
                           const Vector& vertex3) {
  v1 = vertex1;
  v2 = vertex2;
  v3 = vertex3;
}

void Triangle::SetVertices(double x1, double y1, double z1,
                           double x2, double y2, double z2,
                           double x3, double y3, double z3) {
  v1 = Vector(x1, y1, z1);
  v2 = Vector(x2, y2, z2);
  v3 = Vector(x3, y3, z3);
}

}  // namespace rt
