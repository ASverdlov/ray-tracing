#include "geometry/models/sphere.hpp"

#include "algebra/equation_solver.hpp"
#include "geometry/ray.hpp"

namespace rt {

CollisionDescription Sphere::Trace(const Ray& ray) {
  /*
   * (x - center.x) ^ 2 + (y - center.y) ^ 2 + (z - center.z) ^ 2 = r ^ 2
   * x(t) = origin.x + direction.x * t
   * y(t) = origin.y + direction.y * t
   * z(t) = origin.z + direction.z * t
   * => (origin.x + direction.x * t - center.x) ^ 2 +
   *    (origin.y + direction.y * t - center.y) ^ 2 +
   *    (origin.z + direction.z * t - center.z) ^ 2 = r ^ 2
   */
  const Ray& origin = ray.GetOrigin();
  const Ray& direction = ray.GetDirection();
  Equation equation = (Equation(0.0, direction.x, origin.x - center.x) ^ 2) +
                      (Equation(0.0, direction.y, origin.y - center.y) ^ 2) +
                      (Equation(0.0, direction.z, origin.z - center.z) ^ 2) +
                       Equation(0.0, 0.0, -radius * radius);

  vector<double> solutions;
  Solve(equation, back_inserter(solutions));

  CollisionDescription collision;
  for (double solution : solutions) {
      double trace_distance = solution * direction.GetLength();
      Vector touching = origin + direction * solution;

      Vector radius_vector = touching - center;
      double cosinus = (radius_vector * -direction) /
                       (radius * direction.GetLength());

      // TODO(asverdlov, fix till 30.08.16):
      // Encapsulate following logic in CollisionDescription
      if (trace_distance <= 0 ||
          trace_distance >= collision.distance ||
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
