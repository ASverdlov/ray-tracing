#include "ray-tracing/application.hpp"

#include "ray-tracing/render/image.hpp"
#include "ray-tracing/object_factory.hpp"
#include "ray-tracing/geometry/models/triangle.hpp"
#include "ray-tracing/geometry/models/sphere.hpp"

namespace rt {

Application::Application() {
  scene_.SetCamera(&camera_);
}


int Application::Run() {
  renderer_.Render(&scene_, &image_);
  return 0;
}

void Application::SetResolution(size_t width, size_t height) {
  image_.SetResolution(width, height);
  camera_.SetAspectRatio(1.0f * width / height);
}

void Application::SetResolution(const Resolution& resolution) {
  image_.SetResolution(resolution);
  camera_.SetAspectRatio(1.0f * resolution.width / resolution.height);
}

Triangle* Application::CreateTriangle(const std::string& id) {
	auto* triangle = ObjectFactory::Create<Triangle>(id);
  if (triangle) {
    scene_.AttachModel(triangle);
  }
  return triangle;
}

Sphere* Application::CreateSphere(const std::string& id) {
  auto* sphere = ObjectFactory::Create<Sphere>(id);
  if (sphere) {
    scene_.AttachModel(sphere);
  }
  return sphere;
}

Light* Application::CreateLight(const std::string& id) {
  auto* light = ObjectFactory::Create<Light>(id);
  if (light) {
  	scene_.AttachLight(light);
  }
  return light;
}

bool Application::RemoveObject(const std::string& id) {
  return ObjectFactory::Remove(id);
}

}  // namespace rt
