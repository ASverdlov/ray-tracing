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
  return CreateEntity<Triangle>(label);
}

Sphere* Application::CreateSphere(const Label& label) {
  return CreateEntity<Sphere>(label);
}

Light* Application::CreateLight(const Label& label) {
  return CreateEntity<Light>(label);
}

template<typename Entity>
Entity* Application::CreateEntity(const Label& label) {
  auto entity = std::make_unique<Entity>();
  auto insertion_result = storage.emplace(label, std::move(entity));

  auto iterator = insertion_result.first;
  bool was_inserted = insertion_result.second;

  return was_inserted ? iterator->get() : nullptr;
}

template<typename Entity>
bool Application::RemoveEntity(const Label& label) {
  return storage.erase(label) > 0;
}

}  // namespace rt
