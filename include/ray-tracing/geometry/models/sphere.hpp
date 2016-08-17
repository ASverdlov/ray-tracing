#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <object.hpp>
#include <utility.hpp>

class Sphere : public Object {
 public:
  void SetRadius(double radius) { 
    radius_ = radius;
  };

  CollisionDescription Trace(const Ray&) override;

 private:
  double radius_;
};

#endif
