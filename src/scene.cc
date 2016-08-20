#include <scene.hpp>

namespace rt {

bool Scene::AttachModel(Model* model) {
  return AttachEntity(model);
}

bool Scene::AttachLight(Light* light) {
  return AttachEntity(light);
}

template<typename Entity>
bool Scene::AttachEntity(Entity* entity) {
  auto storage = GetEntities<Entity>(); 
  auto insertion_result = storage.insert(entity);

  bool was_inserted = insertion_result.second;
  return was_inserted;
}

bool Scene::DetachModel(Model* model) {
  return DetachEntity(model);
}

bool Scene::DetachLight(Light* light) {
  return DetachEntity(light);
}

template<typename Entity>
bool DetachEntity(Entity* entity) {
  auto storage = GetEntities<Entity>(); 
  return storage.erase(entity) > 0;
}

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
