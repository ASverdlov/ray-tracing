#include "scene/camera.hpp"

namespace rt {

void Camera::SetSize(const Size& size) {
  size_ = size;
}

void Camera::SetDistance(double distance) {
  distance_ = distance;
}

Size GetSize() const {
  return size_;
}

Ray Camera::GetRay(double x, double y) const {
  Vector2d origin(x, y);  // Get a 2D-point on a plane
  // Get a 3D-point in the space
  Vector spot = Get3DPoint(origin);
  return Ray(spot, spot - position_);
}

Vector Camera::Get3DPoint(const Vector2d& coordinate) const {
  // Take plane's basis
  Plane plane = GetPlane();
  // And combinate these together
  return plane.x * coordinate.x + plane.y * coordinate.y + plane.origin;
}

Plane Camera::GetPlane() const {
  // Assume that camera stands in the world's origin
  Vector direction = ...;
  Vector plane_center = direction * distance;

  // Here is plane's basis's origin on the center
  Vector x(1, direction.x / direction.y, 0);  // y basis vector
  x /= x.GetLenght()  // Normalize

  Vector y;  // y basis vector

  return Plane();
}

void Camera::Rotate(const Transform& transform) {
  transform_ = transform;
}

}  // namespace rt
