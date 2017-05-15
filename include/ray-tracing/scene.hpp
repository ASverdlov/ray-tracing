#ifndef SCENE_HPP
#define SCENE_HPP

#include "ray-tracing/models/model.hpp"

#include "ray-tracing/camera.hpp"
#include "ray-tracing/light.hpp"
#include "ray-tracing/macroses.hpp"
#include "ray-tracing/scene_object.hpp"

#include <unordered_set>

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
  Camera* GetCamera() {
    return camera_;
  }

  void SetAmbientLight(double brightness) {
    ambient_light_brightness_ = brightness;
  }
  double GetAmbientLight() const {
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

  Camera* camera_;
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
