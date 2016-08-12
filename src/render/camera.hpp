#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry.hpp>
#include <utility.hpp>

namespace rt {

class Camera {
 public:
  void SetPosition(const Vec3d&);
  void SetPosition(double x, double y, double z);

  void SetTransform(const Transform&);
  void SetTransform(double x1, double y1, double z1,
                    double x2, double y2, double z2,
                    double x3, double y3, double z3);

  void SetFocusDistance(double distance);

  void SetFrameSize(double width, double height);

  Line GetRay(double physical_x, double physical_y);

 private:
  Vec3d position_;
  Transform transform_;
  double focus_distance_;
  double frame_width_;
  double frame_height_;
};

} // namespace rayt

#endif
