#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "geometry/transform.hpp"
#include "utility.hpp"

namespace rt {

class Camera : public Placeable {
 public:
  void SetShape(const Shape& shape);
  Shape GetShape() const;
  void SetDistance(double distance);
  void SetDirection(const Vector& direction);
  Ray GetRay(double x, double y) const;  // Physical coordinates

 private:
  struct Basis {
    // That's a basis
    Vector x;
    Vector y;
  }

  Vector Get3DPoint(const Vector2d& coordinate) const;
  Basis GetBasis() const;
  void UpdateBasis();
  Vector GetBasisCenter() const;

  Vector plane_center_;

  Vector direction_;
  Shape shape_;
  double distance_;
};

}  // namespace rt

#endif
