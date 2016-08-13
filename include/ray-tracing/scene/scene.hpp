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
 private:
  vector<Model*> models_;
  vector<Light*> lights_;
  Camera camera;

  DISABLE_COPYING(Scene);
};

} // namespace rayt

#endif
