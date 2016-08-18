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

}

Sphere* Application::CreateSphere(const Label& label) {

}

Light* Application::CreateLight(const Label& label) {

}

bool Application::RemoveModel(const Label& label) {

}

bool Application::RemoveLight(const Label& label) {

}

} // namespace rt
