#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "ray-tracing/math/ray.hpp"

#include "ray-tracing/models/model.hpp"

#include "ray-tracing/macroses.hpp"
#include "ray-tracing/placeable_mixin.hpp"

namespace rt {

class Sphere : public IModel, public PlaceableMixin {
 public:
  void SetRadius(double radius) {
    radius_ = radius;
  }

  virtual Collision Trace(const Ray&) const override;

 private:
  double radius_;
};

}  // namespace rt

#endif
