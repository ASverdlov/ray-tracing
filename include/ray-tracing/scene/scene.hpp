#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include <scene/camera.hpp>
#include <geometry.hpp>
#include <light.hpp>
#include <utility.hpp>

namespace rt {

using std::vector;

class Scene {
 public:
  void AddModel(Model* model);
  void AddLight(Light* light);

  vector<Model*> GetModels();
  vector<Light*> GetLights();

  void SetCamera(unique_ptr<Camera> camera) { camera_ = std::move(camera); }
  Camera* GetCamera() { return camera_; }

 private:
  vector<Model*> models_;
  vector<Light*> lights_;
  unique_ptr<Camera> camera_;

  DISABLE_COPYING(Scene);
};

} // namespace rayt

#endif
