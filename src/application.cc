#include "application.hpp"

namespace rt {

void Application::Run() {
  Frame bitmask = renderer_.RenderScene(scene_, resolution_);
  window_.Show(bitmask);
}

void Application::SetResolution(int width, int height) {
  SetResolution(Resolution(width, height));
}

void Application::SetResolution(const Resolution& resolution) {
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
