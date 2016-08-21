#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "geometry/models/model.hpp"
#include "geometry/ray.hpp"
#include "utility.hpp"

namespace rt {

class Sphere : public Model, public Placeable {
 public:
  void SetRadius(double radius) {
    radius_ = radius;
  }

  virtual Collision Trace(const Ray&);

 private:
  double radius_;
};

}  // namespace rt

#endif
