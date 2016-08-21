#ifndef MODEL_HPP
#define MODEL_HPP

#include "ray-tracing/geometry/ray.hpp"
#include "ray-tracing/geometry/vector.hpp"
#include "ray-tracing/render/color.hpp"
#include "ray-tracing/utility.hpp"

namespace rt {

struct Collision {
  static const double INFINITY = 1e300;

  Collision() : trace_distance(INFINITY) {}

  double trace_distance;
  double cosinus;
  Vector touching;
  Color color;

  bool IsCloserThan(const Collision& other_collision) const {
    return other_collision.trace_distance < trace_distance;
  }

  bool Exists() const {
    return trace_distance < INFINITY;
  }
};

// Every model has color
// and can be attached to any position
// in space.
class Model {
 public:
  virtual ~Model() {}

  void SetColor(const Color& color) { color_ = color; }
  Color GetColor() { return color_; }

  virtual Collision Trace(const Ray& ray) const = 0;

 private:
  Color color_;
};

}  // namespace rt

#endif
