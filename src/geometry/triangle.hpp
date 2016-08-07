#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <object.hpp>
#include <basics.hpp>

class Triangle : public Object {
 public:
  Triangle() {}
  ~Triangle() {}

  void SetVertices(const Vec3d& v1, const Vec3d& v2, const Vec3d& v3);
  void SetVertices(double x1, double y1, double z1,
                   double x2, double y2, double z2,
                   double x3, double y3, double z3);

 private:
  Vec3d vertices[3];
};

#endif
