#include "ray-tracing/application.hpp"

namespace rt {

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
