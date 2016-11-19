#include "ray-tracing/scene/camera.hpp"
#include <cmath>

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

Ray Camera::GetRay(double x, double y) const {
  Vector spot = CalculateSpot(x, y);
  return Ray(position_, spot - position_);
}

Vector Camera::CalculateSpot(double x, double y) const {
  Vector x_axis(1, 0, 0),
         y_axis(0, 1, 0),
         z_axis(0, 0, 1);
  Vector center = position_ + x_axis;
  return center +
         z_axis * (Height() / 2 - y * Height()) +
         y_axis * (Width() / 2 - x * Width());
}

float Camera::Height() const {
  return Width() / ratio_;
}

float Camera::Width() const {
  return 2 * std::tan(field_of_view_ * .5f);
}

}  // namespace rt
