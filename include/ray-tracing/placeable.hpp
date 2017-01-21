#ifndef PLACEABLE_HPP
#define PLACEABLE_HPP

#include "ray-tracing/geometry/vector.hpp"

namespace rt {

class Placeable {
 public:
  void SetPosition(const Vector& position) { position_ = position; }
  void SetPosition(double x, double y, double z) {
    position_ = Vector(x, y, z);
  }

  Vector GetPosition() const {
    return position_;
  }
 protected:
  Vector position_;
};

}  // namespace rt

#endif
