#ifndef SCENE_HPP
#define SCENE_HPP

#include "ray-tracing/macroses.hpp"

#include <unordered_set>

namespace rt {
  class IModel;

  class Camera;
  class Light;
}

namespace rt {

class Scene {
 public:
  template<typename T>
  using Objects = std::unordered_set<T>;

 public:
  Scene() {}

  bool AttachModel(IModel* model);
  bool DetachModel(IModel* model);
  const Objects<IModel*>& Models() const;

  bool AttachLight(Light* light);
  bool DetachLight(Light* light);
  const Objects<Light*>& Lights() const;


  void SetCamera(Camera* camera) {
    camera_ = camera;
  }
  Camera* Camera() {
    return camera_;
  }

  void SetAmbientLight(double brightness) {
    ambient_light_brightness_ = brightness;
  }
  double AmbientLight() const {
    return ambient_light_brightness_;
  }

 private:
  template<typename T>
  bool AttachObject(T* object);

  template<typename T>
  bool DetachObject(T* object);

  template<typename T>
  Objects<T*>& ObjectsByType();

  template<typename T>
  const Objects<T*>& ObjectsByType() const;

 private:
  Objects<IModel*> models_;
  Objects<Light*> lights_;

  class Camera* camera_;
  double ambient_light_brightness_;

  DISABLE_COPYING(Scene);
};

template<typename T>
bool Scene::AttachObject(T* object) {
  auto& objects = ObjectsByType<T>();
  auto insertion_info = objects.insert(object);
  return insertion_info.second;
}

template<typename T>
bool Scene::DetachObject(T* object) {
  auto& objects = ObjectsByType<T>();
  return objects.erase(object) > 0;
}

}  // namespace rt

#endif
