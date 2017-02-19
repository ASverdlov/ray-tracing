#include "ray-tracing/scene/scene.hpp"

namespace rt {

bool Scene::AttachModel(Model* model) {
  return AttachObject(model);
}

bool Scene::AttachLight(Light* light) {
  return AttachObject(light);
}

bool Scene::DetachModel(Model* model) {
  return DetachObject(model);
}

bool Scene::DetachLight(Light* light) {
  return DetachObject(light);
}

template<>
typename Scene::Storage<Model*>& Scene::GetObjects<Model>() {
  return models_;
}

template<>
typename Scene::Storage<Light*>& Scene::GetObjects<Light>() {
  return lights_;
}

template<>
const typename Scene::Storage<Model*>& Scene::GetObjects<Model>() const {
  return models_;
}

template<>
const typename Scene::Storage<Light*>& Scene::GetObjects<Light>() const {
  return lights_;
}

const typename Scene::Storage<Model*>& Scene::GetModels() const {
  return GetObjects<Model>();
}

const typename Scene::Storage<Light*>& Scene::GetLights() const {
  return GetObjects<Light>();
}

}  // namespace rt
