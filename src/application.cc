#include "ray-tracing/application.hpp"

namespace rt {

template<typename Object>
Object* Application::CreateObject(const ID& id) {
  auto object = std::make_unique<Object>();
  auto insertion_result = objects.emplace(id, std::move(object));

  auto pointer_to_object = insertion_result.first->second.get();
  bool was_inserted = insertion_result.second;

  return was_inserted ? static_cast<Object*>(pointer_to_object) : nullptr;
}

bool Application::RemoveObject(const ID& id) {
  return objects.erase(id) > 0;
}

int Application::Run() {
  Frame bitmask = renderer_.RenderScene(&scene_, window_.GetResolution());
  window_.Show(bitmask);
  return 0;
}

void Application::SetWindowResolution(int width, int height) {
  window_.SetResolution(width, height);
}

void Application::SetWindowResolution(const Resolution& resolution) {
  window_.SetResolution(resolution);
}

Triangle* Application::CreateTriangle(const ID& id) {
  return CreateObject<Triangle>(id);
}

Sphere* Application::CreateSphere(const ID& id) {
  return CreateObject<Sphere>(id);
}

Light* Application::CreateLight(const ID& id) {
  return CreateObject<Light>(id);
}

}  // namespace rt
