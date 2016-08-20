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
    // Left up corner
    Vector origin;
    // That's a basis
    Vector x;
    Vector y;
  }

  Vector direction_;
  Size size_;
};

}  // namespace rt

#endif
