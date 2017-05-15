#ifndef PLACEABLE_MIXIN_HPP
#define PLACEABLE_MIXIN_HPP

#include "ray-tracing/math/vector.hpp"

namespace rt {

class PlaceableMixin {
 public:
  void SetPosition(const Vector& position) {
    position_ = position;
  }

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
