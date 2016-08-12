#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include <geometry.hpp>
#include <intersection.hpp>
#include <light.hpp>
#include <utility.hpp>

namespace rt {

using std::vector;

class Scene {
public:
  vector<Model*> GetModels() const;
  vector<Light*> GetLights() const;

  void AddModel(Model* model);
  void AddLight(Light* light);

private:
  vector<Model*> models_;
  vector<Light*> lights_;

  DISABLE_COPYING(Scene);
};

} // namespace rayt

#endif
