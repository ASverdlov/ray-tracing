#include <scene.hpp>

namespace rt {

const typename Scene::Storage<Model*> GetModels() const {
  return GetEntities<Model>();
}

const typename Scene::Storage<Light*> GetLights() const {
  return GetEntities<Light>();
}

template
typename Scene::Storage<Model*> GetEntities<Model>() {
  return models_; 
}

template
typename Scene::Storage<Light*> GetEntities<Light>() {
  return lights_; 
}

template
const typename Scene::Storage<Model*> GetEntities<Model>() const {
  return models_; 
}

template
const typename Scene::Storage<Light*> GetEntities<Light>() const {
  return lights_; 
}

} // namespace rt
