#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <point.hpp>
#include <utility.hpp>

namespace rt {

class Light {
 public:
  Light(const Vec3d&);

  Vec3d GetPosition() const;

 private:
  Vec3d position_;
};

} // namespace rt

#endif
