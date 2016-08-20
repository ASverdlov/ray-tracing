#ifndef SCENE_HPP
#define SCENE_HPP

#include <unordered_set>

#include <geometry.hpp>
#include <light.hpp>
#include <utility.hpp>
#include <scene/camera.hpp>

namespace rt {

using std::unordered_set;

class Scene {
 public:
  bool AttachModel(Model* model);
  bool AttachLight(Light* light);

  bool DetachModel(Model* model);
  bool DetachLight(Light* light);

  template<typename Entity>
  class SceneStorage: unordered_set<Entity> {};

  const SceneStorage<Model*>& GetModels() const;
  const SceneStorage<Light*>& GetLights() const;

  void SetCamera(Camera* camera) { camera_ = camera; }
  Camera* GetCamera() { return camera_; }

 private:
  SceneStorage<Model*> models_;
  SceneStorage<Light*> lights_;
  Camera* camera_;

  template<typename Entity>
  bool AttachEntity(Entity* entity);

  DISABLE_COPYING(Scene);
};

} // namespace rt

#endif
