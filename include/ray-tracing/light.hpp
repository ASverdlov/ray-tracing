#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "ray-tracing/placeable_mixin.hpp"
#include "ray-tracing/scene_object.hpp"

namespace rt {

class Light
  : public ISceneObject
  , public PlaceableMixin
{};

}  // namespace rt

#endif
