#include "scene/camera.hpp"

namespace rt {

void Camera::SetSize(const Size& size) {
  size_ = size;
}

Size GetSize() const {
  return size_;
}

void Camera::SetDistance(double distance) {
  distance_ = distance;
}

void Camera::SetDirection(const Vector& direction) {
  direction_ = direction;
  UpdatePlane();
}

Ray Camera::GetRay(double x, double y) const {
  Vector2d origin(x, y);  // Get a 2D-point on a plane
  // Get a 3D-point in the space
  Vector spot = Get3DPoint(origin);
  return Ray(spot, spot - position_);
}

Vector Camera::Get3DPoint(const Vector2d& coordinate) const {
  // Take plane's basis
  // And combinate these together
  Vector plane_center = GetPlaneCenter();
  Vector origin = plane_.x * (size_.width * -.5) +
                  plane_.y * (size_.height * -.5) +
                  plane_center;
  return plane_.x * coordinate.x + plane_.y * coordinate.y + origin;
}

Plane Camera::GetPlane() const {
  Vector plane_center = GetPlaneCenter();
  Vector plane_normal = plane_center.Normalize();

  // Here is orthonormal plane's basis
  Vector x = Vector(0, 0, 1) % plane_normal;
  Vector y = x % plane_center;
  return Plane(x * (-1), y * (-1));
}

void UpdatePlane() {
  plane_ = GetPlane();
}

Vector GetPlaneCenter() const {
  return direction_ * distance_ + position_;
}

}  // namespace rt
