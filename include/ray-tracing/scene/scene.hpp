#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include <geometry.hpp>
#include <light.hpp>
#include <utility.hpp>
#include <scene/camera.hpp>

namespace rt {

using std::vector;

class Scene {
 public:
  bool AttachModel(Model* model);
  bool AttachLight(Light* light);

  bool DetachModel(Model* model);
  bool DetachLight(Light* light);

  const unordered_set<Model*>& GetModels() const;
  const unordered_set<Light*>& GetLights() const;

  void SetCamera(Camera* camera) { camera_ = camera; }
  Camera* GetCamera() { return camera_; }

 private:
  unordered_set<Model*> models_;
  unordered_set<Light*> lights_;
  Camera* camera_;

  DISABLE_COPYING(Scene);
};

} // namespace rayt

#endif
