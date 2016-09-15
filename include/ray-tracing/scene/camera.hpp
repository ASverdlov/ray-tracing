#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cmath>

#include "ray-tracing/utility.hpp"

namespace rt {

class Camera : public Placeable {
 public:
  Camera()
    : distance_(1.0f),
      field_of_view_(M_PI / 3.0)
  {}

  void SetAspectRatio(float ratio);
  float GetAspectRatio() const;

  void SetFieldOfView(float radians);
  float GetFieldOfView() const;

  Ray GetRay(int x, int y) const;

 private:
  double distance_;
  float field_of_view_;
  float ratio_;
};

}  // namespace rt

#endif
