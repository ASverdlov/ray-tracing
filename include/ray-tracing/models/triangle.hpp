#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "ray-tracing/models/model.hpp"

#include "ray-tracing/math/ray.hpp"
#include "ray-tracing/math/vector.hpp"

#include "ray-tracing/placeable_mixin.hpp"

namespace rt {

class Triangle : public IModel, public PlaceableMixin {
 public:
  void SetVertices(const Vector& vertex1, const Vector& vertex2, const Vector& vertex3);
  void SetVertices(double x1, double y1, double z1,
                   double x2, double y2, double z2,
                   double x3, double y3, double z3);

  virtual Collision Trace(const Ray&) const override;

 private:
  Vector v1;
  Vector v2;
  Vector v3;
};

}  // namespace rt

#endif
