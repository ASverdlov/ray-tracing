#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "ray-tracing/geometry/vector.hpp"
#include "ray-tracing/placeable.hpp"
#include "ray-tracing/utility.hpp"
#include "ray-tracing/object.hpp"

namespace rt {

class Light : public Placeable, public Object {
};

}  // namespace rt

#endif
