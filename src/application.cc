#include "ray-tracing/application.hpp"

namespace rt {

template<typename Object>
Object* Application::CreateObject(const ID& id) {
  auto object = std::make_unique<Object>();
  auto insertion_result = objects.emplace(id, std::move(object));

  auto* pointer_to_object = insertion_result.first->second.get();
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
  scene_.GetCamera()->SetAspectRatio(1.0f * width / height);
}

void Application::SetWindowResolution(const Resolution& resolution) {
  window_.SetResolution(resolution);
}

Triangle* Application::CreateTriangle(const ID& id) {
  Triangle* triangle = CreateObject<Triangle>(id);
  if (triangle != nullptr) {
    scene_.AttachModel(triangle);
  }
  return triangle;
}

Sphere* Application::CreateSphere(const ID& id) {
  Sphere* sphere = CreateObject<Sphere>(id);
  if (sphere != nullptr) {
    scene_.AttachModel(sphere);
  }
  return sphere;
}

Light* Application::CreateLight(const ID& id) {
  Light* light = CreateObject<Light>(id);
  if (light != nullptr) {
    scene_.AttachLight(light);
  }
  return light;
}

}  // namespace rt
