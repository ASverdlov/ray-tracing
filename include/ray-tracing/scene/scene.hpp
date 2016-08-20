#ifndef SCENE_HPP
#define SCENE_HPP

#include <unordered_set>

#include "geometry.hpp"
#include "render/light.hpp"
#include "scene/camera.hpp"
#include "utility.hpp"

namespace rt {

using std::unordered_set;

class Scene {
 public:
  bool AttachModel(Model* model);
  bool AttachLight(Light* light);

  bool DetachModel(Model* model);
  bool DetachLight(Light* light);

  template<typename T>
  class Storage: unordered_set<T> {};

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

  template<typename Entity>
  bool AttachEntity(Entity* entity);

  template<typename Entity>
  bool DetachEntity(Entity* entity);

  template<typename Entity>
  Storage<Entity*>& GetEntities();

  template<typename Entity>
  const Storage<Entity*>& GetEntities() const;

  DISABLE_COPYING(Scene);
};

template<typename Entity>
bool Scene::AttachEntity(Entity* entity) {
  auto storage = GetEntities<Entity>();
  auto insertion_result = storage.insert(entity);

  bool was_inserted = insertion_result.second;
  return was_inserted;
}

template<typename Entity>
bool DetachEntity(Entity* entity) {
  auto storage = GetEntities<Entity>();
  return storage.erase(entity) > 0;
}

}  // namespace rt

#endif
