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
