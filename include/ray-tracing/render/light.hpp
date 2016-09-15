#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "ray-tracing/geometry/vector.hpp"
#include "ray-tracing/utility.hpp"
#include "ray-tracing/entity.hpp"

namespace rt {

class Light : public Placeable, public Entity {
};

}  // namespace rt

#endif
