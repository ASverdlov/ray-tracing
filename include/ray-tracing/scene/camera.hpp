#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "ray-tracing/algebra/transform.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

class Camera : public Placeable {
 public:
  void SetAspectRatio(float ratio);
  float GetAspectRatio() const;

  void SetFieldOfView(float radians);
  float GetFieldOfView() const;

  Ray GetRay(int x, int y) const;

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
