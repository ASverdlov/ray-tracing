#include <application.hpp>

namespace rt {

void Application::Run() {
  Frame bitmask = renderer_.RenderScene(scene_, resolution_);
  window_.Show(bitmask);
}

void Application::SetResolution(int width, int height) {
  SetResolution(Resolution(width, height));
}

void Application::SetResolution(const Reolution& resolution) {
  window_.SetResolution(resolution);
}

Triangle* Application::CreateTriangle(const Label& label) {
  return CreateEntity<Triangle, ModelStorage>(model_storage_, label);
}

Sphere* Application::CreateSphere(const Label& label) {
  return CreateEntity<Sphere, ModelStorage>(model_storage_, label);
}

Light* Application::CreateLight(const Label& label) {
  return CreateEntity<Light, LightStorage>(light_storage_, label);
}

template<typename EntityType, typename StorageType>
EntityType* Application::CreateEntity(StorageType& storage, const Label& label) {
  auto entity = std::make_unique<EntityType>();
  auto insertion_result = storage.emplace(label, std::move(entity));

  auto iterator = insertion_result.first;
  bool was_inserted = insertion_result.second;

  return was_inserted ? iterator->get() : nullptr;
}

bool Application::RemoveModel(const Label& label) {
  return RemoveEntity<Model, ModelStorage>(model_storage_, label);
}

bool Application::RemoveLight(const Label& label) {
  return RemoveEntity<Light, LightStorage>(light_storage_, label);
}

template<typename EntityType, typename StorageType>
bool Application::RemoveEntity(StorageType& storage, const Label& label) {
  return storage.erase(label) > 0;
}

} // namespace rt
