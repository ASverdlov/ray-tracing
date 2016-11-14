#ifndef SCENE_HPP
#define SCENE_HPP

#include <unordered_set>

#include "ray-tracing/geometry.hpp"
#include "ray-tracing/render/light.hpp"
#include "ray-tracing/scene/camera.hpp"
#include "ray-tracing/utility.hpp"
#include "ray-tracing/object.hpp"

namespace rt {

using std::unordered_set;

class Scene {
 public:
  Scene() {}

  bool AttachModel(Model* model);
  bool AttachLight(Light* light);

  bool DetachModel(Model* model);
  bool DetachLight(Light* light);

  template<typename T>
  class Storage : public unordered_set<T> {};

  const Storage<Model*>& GetModels() const;
  const Storage<Light*>& GetLights() const;

  void SetCamera(Camera* camera) { camera_ = camera; }
  Camera* GetCamera() { return camera_; }

  void SetAmbientLight(double brightness) {
    ambient_light_brightness_ = brightness;
  }
  double GetAmbientLight() const {
    return ambient_light_brightness_;
  }

 private:
  Storage<Model*> models_;
  Storage<Light*> lights_;
  Camera* camera_;
  double ambient_light_brightness_;

  template<typename Object>
  bool AttachObject(Object* object);

  template<typename Object>
  bool DetachObject(Object* object);

  template<typename Object>
  Storage<Object*>& GetObjects();

  template<typename Object>
  const Storage<Object*>& GetObjects() const;

  DISABLE_COPYING(Scene);
};

template<typename Object>
bool Scene::AttachObject(Object* object) {
  auto& storage = GetObjects<Object>();
  auto insertion_result = storage.insert(object);

  bool was_inserted = insertion_result.second;
  return was_inserted;
}

template<typename Object>
bool Scene::DetachObject(Object* object) {
  auto& storage = GetObjects<Object>();
  return storage.erase(object) > 0;
}

}  // namespace rt

#endif
