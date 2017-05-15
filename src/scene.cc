#include "ray-tracing/scene.hpp"

namespace rt {

bool Scene::AttachModel(IModel* model) {
  return AttachObject(model);
}

bool Scene::AttachLight(Light* light) {
  return AttachObject(light);
}

bool Scene::DetachModel(IModel* model) {
  return DetachObject(model);
}

bool Scene::DetachLight(Light* light) {
  return DetachObject(light);
}

template<>
typename Scene::Objects<IModel*>& Scene::ObjectsByType<IModel>() {
  return models_;
}

template<>
typename Scene::Objects<Light*>& Scene::ObjectsByType<Light>() {
  return lights_;
}

template<>
const typename Scene::Objects<IModel*>& Scene::ObjectsByType<IModel>() const {
  return models_;
}

template<>
const typename Scene::Objects<Light*>& Scene::ObjectsByType<Light>() const {
  return lights_;
}

const typename Scene::Objects<IModel*>& Scene::Models() const {
  return ObjectsByType<IModel>();
}

const typename Scene::Objects<Light*>& Scene::Lights() const {
  return ObjectsByType<Light>();
}

}  // namespace rt
