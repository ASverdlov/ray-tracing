#include "ray-tracing/scene/scene.hpp"
#include "ray-tracing/geometry.hpp"

namespace rt {

bool Scene::AttachModel(Model* model) {
  return AttachEntity(model);
}

bool Scene::AttachLight(Light* light) {
  return AttachEntity(light);
}

bool Scene::DetachModel(Model* model) {
  return DetachEntity(model);
}

bool Scene::DetachLight(Light* light) {
  return DetachEntity(light);
}

template<>
typename Scene::Storage<Model*>& Scene::GetEntities<Model>() {
  return models_;
}

template<>
typename Scene::Storage<Light*>& Scene::GetEntities<Light>() {
  return lights_;
}

template<>
const typename Scene::Storage<Model*>& Scene::GetEntities<Model>() const {
  return models_;
}

template<>
const typename Scene::Storage<Light*>& Scene::GetEntities<Light>() const {
  return lights_;
}

const typename Scene::Storage<Model*>& Scene::GetModels() const {
  return GetEntities<Model>();
}

const typename Scene::Storage<Light*>& Scene::GetLights() const {
  return GetEntities<Light>();
}

}  // namespace rt
