#include "ray-tracing/application.hpp"

namespace rt {

void Application::Run() {
  Frame bitmask = renderer_.RenderScene(scene_, resolution_);
  window_.Show(bitmask);
}

void Application::SetWindowResolution(int width, int height) {
  window_.SetResolution(width, height);
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

}  // namespace rt
