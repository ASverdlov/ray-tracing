#include "scene/camera.hpp"

namespace rt {

void Camera::SetShape(const Shape& shape) {
  shape_ = shape;
}

Shape GetShape() const {
  return shape_;
}

void Camera::SetDistance(double distance) {
  distance_ = distance;
  UpdateBasis();
}

void Camera::SetDirection(const Vector& direction) {
  direction_ = direction;
  UpdateBasis();
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
  Vector plane_center = GetBasisCenter();
  Vector origin = plane_.x * (shape_.width * -.5) +
                  plane_.y * (shape_.height * -.5) +
                  plane_center;
  return plane_.x * coordinate.x + plane_.y * coordinate.y + origin;
}

Basis Camera::GetBasis() const {
  Vector plane_center = GetBasisCenter();
  Vector plane_normal = plane_center.Normalize();

  // Here is orthonormal plane's basis
  Vector x = Vector(0, 0, 1) % plane_normal;
  Vector y = x % plane_center;
  return Basis(x * (-1), y * (-1));
}

void UpdateBasis() {
  plane_ = GetBasis();
}

Vector GetBasisCenter() const {
  return direction_ * distance_ + position_;
}

}  // namespace rt
