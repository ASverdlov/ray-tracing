#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "ray-tracing/math/vector.hpp"
#include "ray-tracing/math/ray.hpp"

#include "ray-tracing/macroses.hpp"
#include "ray-tracing/placeable_mixin.hpp"

#include <cmath>


namespace rt {

class Camera : public PlaceableMixin {
 public:
  Camera()
    : field_of_view_(M_PI / 3.0)
  {}

  void SetAspectRatio(float ratio);
  float AspectRatio() const;

  void SetFieldOfView(float radians);
  float FieldOfView() const;

  Ray ViewRay(double x, double y) const;

 private:
  Vector CalculateSpot(double x, double y) const;
  float Height() const;
  float Width() const;

  float field_of_view_;
  float ratio_;
};

}  // namespace rt

#endif
