#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ray.hpp>
#include <vector.hpp>
#include <color.hpp>
#include <utility.hpp>

// Forward declaration
class Object;

struct CollisionDescription {
  Object *object;
  double trace_distance;
  double cosinus;
  Vector touching;
};

// Every object has color
// and can be attached to any position
// in space.
class Object : public Placeable {
 public:
  virtual ~Object() {}

  void SetColor(const Color& color) { color_ = color; };

  virtual CollisionDescription Trace(const Ray& ray) = 0;

 private:
  Color color_;
};

#endif
