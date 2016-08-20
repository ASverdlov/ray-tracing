#ifndef MODEL_HPP
#define MODEL_HPP

#include "geometry/ray.hpp"
#include "geometry/vector.hpp"
#include "render/color.hpp"
#include "utility.hpp"

namespace rt {

struct CollisionDescription {
  static const double INFINITY = 1e300;

  CollisionDescription() : trace_distance(INFINITY) {}

  double trace_distance;
  double cosinus;
  Vector touching;
  Color color;

  bool IsCloserThan(const CollisionDescription& other_collision) const {
    return other_collision.trace_distance < trace_distance;
  }

  bool Exists() const {
    return trace_distance < INFINITY;
  }
};

// Every model has color
// and can be attached to any position
// in space.
class Model : public Placeable {
 public:
  virtual ~Model() {}

  void SetColor(const Color& color) { color_ = color; }
  Color GetColor() { return color_; }

  virtual CollisionDescription Trace(const Ray& ray) const = 0;

 private:
  Color color_;
};

}  // namespace rt

#endif
