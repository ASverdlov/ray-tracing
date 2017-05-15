#ifndef MODEL_HPP
#define MODEL_HPP

#include "ray-tracing/math/ray.hpp"
#include "ray-tracing/math/vector.hpp"

#include "ray-tracing/color.hpp"
#include "ray-tracing/macroses.hpp"
#include "ray-tracing/scene_object.hpp"


namespace rt {

struct Collision {
  static constexpr double HUGE_DISTANCE = 1e300;

  Collision()
    : trace_distance(HUGE_DISTANCE)
  {}

  bool IsCloserThan(const Collision& other_collision) const {
    return trace_distance < other_collision.trace_distance;
  }

  bool Exists() const {
    return trace_distance < HUGE_DISTANCE;
  }

  double trace_distance;
  double cosine;
  Vector touching;
  Color color;
};

class IModel : public ISceneObject {
 public:
  virtual ~IModel() {}

  virtual Collision Trace(const Ray& ray) const = 0;

  void SetColor(const Color& color) {
    color_ = color;
  }

  void SetColor(float r, float g, float b) {
    color_ = Color(r, g, b);
  }

  Color GetColor() const {
    return color_;
  }

 protected:
  Color color_;
};

}  // namespace rt

#endif
