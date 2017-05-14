#ifndef MODEL_HPP
#define MODEL_HPP

#include "ray-tracing/geometry/ray.hpp"
#include "ray-tracing/geometry/vector.hpp"
#include "ray-tracing/render/color.hpp"
#include "ray-tracing/utility.hpp"
#include "ray-tracing/object.hpp"


namespace rt {

struct Collision {
  static constexpr double HUGE_DISTANCE = 1e300;

  Collision() : trace_distance(HUGE_DISTANCE) {}

  double trace_distance;
  double cosinus;
  Vector touching;
  Color color;

  bool IsCloserThan(const Collision& other_collision) const {
    return trace_distance < other_collision.trace_distance;
  }

  bool Exists() const {
    return trace_distance < HUGE_DISTANCE;
  }
};

class Model : public Object {
 public:
  virtual ~Model() {}

  void SetColor(const Color& color) { color_ = color; }
  void SetColor(float r, float g, float b) { color_ = Color(r, g, b); }
  Color GetColor() const { return color_; }

  virtual Collision Trace(const Ray& ray) const = 0;

 protected:
  Color color_;
};

}  // namespace rt

#endif
