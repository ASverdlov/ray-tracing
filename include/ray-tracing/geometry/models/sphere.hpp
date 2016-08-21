#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "ray-tracing/geometry/models/model.hpp"
#include "ray-tracing/geometry/ray.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Sphere : public Model, public Placeable {
 public:
  void SetRadius(double radius) {
    radius_ = radius;
  }

  virtual Collision Trace(const Ray&) const;

 private:
  double radius_;
};

}  // namespace rt

#endif
