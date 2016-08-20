#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "geometry/transform.hpp"
#include "utility.hpp"

namespace rt {

class Camera : public Placeable {
 public:
  void SetTransform(const Transform& transform) { transform_ = transform; }
 private:
  Transform transform_;
  double focus_distance_;
  double frame_width_;
  double frame_height_;
};

}  // namespace rt

#endif
