#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "geometry.hpp"
#include "utility.hpp"

namespace rt {

class Camera : public Placeable {
 public:
  void SetSize(const Size& size);
  Size GetSize() const;
  void SetDistance(double distance);
  void SetDirection(const Vector& direction);
  Ray GetRay(double x, double y) const;  // Physical coordinates

 private:
  struct Plane {
    // That's a basis
    Vector x;
    Vector y;
  }

  Vector Get3DPoint(const Vector2d& coordinate) const;
  Plane GetPlane() const;
  void UpdatePlane();
  Vector GetPlaneCenter() const;

  Vector plane_center_;

  Vector direction_;
  Size size_;
  double distance_;
};

}  // namespace rt

#endif
