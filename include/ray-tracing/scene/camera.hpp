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

  Ray GetRay(double x, double y) const;  // Physical coordinates

  void Rotate(const Transform& transform) { transform_ = transform; }

 private:
  struct Plane {
    // Left up corner
    Vector origin;
    // That's a basis
    Vector x;
    Vector y;
  }

  Transform transform_;
  double distance_;
  Size size_;
};

}  // namespace rt

#endif
