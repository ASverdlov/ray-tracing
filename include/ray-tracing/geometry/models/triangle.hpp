#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "geometry/models/model.hpp"
#include "geometry/ray.hpp"
#include "geometry/vector.hpp"

class Triangle : public Model {
 public:
  void SetVertices(const Vector& v1, const Vector& v2, const Vector& v3);
  void SetVertices(double x1, double y1, double z1,
                   double x2, double y2, double z2,
                   double x3, double y3, double z3);

  CollisionDescription Trace(const Ray&) override;

 private:
  Vector vertices_[3];
};

#endif
