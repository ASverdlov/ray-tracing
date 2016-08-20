#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ray.hpp>
#include <vector.hpp>
#include <color.hpp>
#include <utility.hpp>

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

// Every object has color
// and can be attached to any position
// in space.
class Object : public Placeable {
 public:
  virtual ~Object() {}

  void SetColor(const Color& color) { color_ = color; }
  Color GetColor() { return color_; }

  virtual CollisionDescription Trace(const Ray& ray) const = 0;

 private:
  Color color_;
};

#endif
