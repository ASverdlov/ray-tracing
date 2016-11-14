#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cmath>

#include "ray-tracing/utility.hpp"
#include "ray-tracing/geometry/vector.hpp"
#include "ray-tracing/geometry/ray.hpp"

namespace rt {

class Camera : public Placeable {
 public:
  Camera()
    : field_of_view_(M_PI / 3.0)
  {}

  void SetAspectRatio(float ratio);
  float GetAspectRatio() const;

  void SetFieldOfView(float radians);
  float GetFieldOfView() const;

  Ray GetRay(int x, int y) const;

 private:
  Vector CalculateSpot(int x, int y) const;
  float Height() const;
  float Width() const;

  float field_of_view_;
  float ratio_;
};

}  // namespace rt

#endif
