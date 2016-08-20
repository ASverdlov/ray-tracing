#ifndef SCENE_HPP
#define SCENE_HPP

#include <unordered_set>

#include "geometry.hpp"
#include "light.hpp"
#include "utility.hpp"
#include "scene/camera.hpp"

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

 private:
  Storage<Model*> models_;
  Storage<Light*> lights_;
  Camera* camera_;

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

}  // namespace rt

#endif
