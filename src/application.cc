#include "ray-tracing/application.hpp"

#include "ray-tracing/models/triangle.hpp"
#include "ray-tracing/models/sphere.hpp"

#include "ray-tracing/scene_object_manager.hpp"


namespace rt {

Application::Application()
  : image_()
  , scene_()
  , camera_()
  , renderer_(&scene_, &image_)
{
  scene_.SetCamera(&camera_);
  scene_.SetAmbientLight(2.3);
}

int Application::Run() {
  renderer_.Render();
  return 0;
}

void Application::SetResolution(size_t width, size_t height) {
  image_.SetResolution(width, height);
  camera_.SetAspectRatio(1.f * width / height);
}

void Application::SetResolution(const Resolution& resolution) {
  image_.SetResolution(resolution);
  camera_.SetAspectRatio(1.f * resolution.width / resolution.height);
}

Triangle* Application::CreateTriangle(const std::string& id) {
  auto* triangle = SceneObjectManager::Create<Triangle>(id);
  if (triangle) {
    scene_.AttachModel(triangle);
  }
  return triangle;
}

Sphere* Application::CreateSphere(const std::string& id) {
  auto* sphere = SceneObjectManager::Create<Sphere>(id);
  if (sphere) {
    scene_.AttachModel(sphere);
  }
  return sphere;
}

Light* Application::CreateLight(const std::string& id) {
  auto* light = SceneObjectManager::Create<Light>(id);
  if (light) {
    scene_.AttachLight(light);
  }
  return light;
}

bool Application::RemoveObject(const std::string& id) {
  return SceneObjectManager::Remove(id);
}

}  // namespace rt
