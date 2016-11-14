#include <cmath>

#include "ray-tracing/scene/camera.hpp"

namespace rt {

void Camera::SetAspectRatio(float ratio) {
  ratio_ = ratio;
}

float Camera::GetAspectRatio() const {
  return ratio_;
}

void Camera::SetFieldOfView(float radians) {
  field_of_view_ = radians;
}

float Camera::GetFieldOfView() const {
  return field_of_view_;
}

Ray Camera::GetRay(int x, int y) const {
  Vector spot = CalculateSpot(x, y);
  return Ray(position_, spot - position_);
}

Vector Camera::CalculateSpot(int x, int y) const {
  Vector x_axis(1, 0, 0),
         y_axis(0, 1, 0),
         z_axis(0, 0, 1);
  Vector center = position_ + x_axis;
  return center +
         z_axis * (Height() / 2 - x) +
         y_axis * (Width() / 2 - y);
}

float Camera::Height() const {
  return Width() / ratio_;
}

float Camera::Width() const {
  return 2 * std::tan(field_of_view_ * .5f);
}

}  // namespace rt
