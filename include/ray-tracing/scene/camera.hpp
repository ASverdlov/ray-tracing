#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry.hpp>
#include <utility.hpp>

namespace rt {

class Camera {
 public:


 private:
  Vec3d position_;
  Transform transform_;
  double focus_distance_;
  double frame_width_;
  double frame_height_;
};

} // namespace rayt

#endif
