#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <color.hpp>
#include <utils.hpp>

// Every object has color
class Object {
 public:
  virtual ~Object() {}

  void SetColor(Color color);

  void SetPosition(Vec3d position);
  void SetPosition(double x, double y, double z);

 private:
  Color color_;
  Vec3d position_;
};

#endif
