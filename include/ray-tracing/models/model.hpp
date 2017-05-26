#ifndef MODEL_HPP
#define MODEL_HPP

#include "ray-tracing/collision.hpp"

#include "ray-tracing/math/ray.hpp"
#include "ray-tracing/math/vector.hpp"

#include "ray-tracing/color.hpp"
#include "ray-tracing/macroses.hpp"
#include "ray-tracing/scene_object.hpp"


namespace rt {

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
