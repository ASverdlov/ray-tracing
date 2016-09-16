#include <vector>

#include "ray-tracing/geometry/models/sphere.hpp"
#include "ray-tracing/geometry/ray.hpp"
#include "ray-tracing/geometry/vector.hpp"
#include "ray-tracing/algebra/equation_solver.hpp"

namespace rt {

Collision Sphere::Trace(const Ray& ray) const {
  /*
   * (x - center.x) ^ 2 + (y - center.y) ^ 2 + (z - center.z) ^ 2 = r ^ 2
   * x(t) = origin.x + direction.x * t
   * y(t) = origin.y + direction.y * t
   * z(t) = origin.z + direction.z * t
   * => (origin.x + direction.x * t - center.x) ^ 2 +
   *    (origin.y + direction.y * t - center.y) ^ 2 +
   *    (origin.z + direction.z * t - center.z) ^ 2 = r ^ 2
   */
  const Vector& origin = ray.GetOrigin();
  const Vector& direction = ray.GetDirection();
  Equation equation = (Equation(0.0, direction.x, origin.x - position_.x) ^ 2) +
                      (Equation(0.0, direction.y, origin.y - position_.y) ^ 2) +
                      (Equation(0.0, direction.z, origin.z - position_.z) ^ 2) +
                       Equation(0.0, 0.0, -radius_ * radius_);

  std::vector<double> solutions;
  Solve(equation, back_inserter(solutions));

  Collision collision;
  for (double solution : solutions) {
      double trace_distance = solution * direction.GetLength();
      Vector touching = origin + direction * solution;

      Vector radius_vector = touching - position_;
      double cosinus = (radius_vector * -direction) /
                       (radius_ * direction.GetLength());

      // TODO(asverdlov, fix till 30.08.16):
      // Encapsulate following logic in Collision
      if (trace_distance <= 0 ||
          trace_distance >= collision.trace_distance ||
          cosinus <= 0) {
          continue;
      }
      collision.touching = touching;
      collision.trace_distance = trace_distance;
      collision.cosinus = cosinus;
      collision.color = color_;
  }
  return collision;
}

}  // namespace rt
