#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "geometry/models/model.hpp"
#include "geometry/ray.hpp"
#include "utility.hpp"

class Sphere : public Model {
 public:
  void SetRadius(double radius) {
    radius_ = radius;
  }

  CollisionDescription Trace(const Ray&) override;

 private:
  double radius_;
};

#endif
