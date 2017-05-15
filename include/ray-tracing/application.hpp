#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "ray-tracing/models/triangle.hpp"
#include "ray-tracing/models/sphere.hpp"

#include "ray-tracing/renderer.hpp"
#include "ray-tracing/image.hpp"
#include "ray-tracing/light.hpp"
#include "ray-tracing/camera.hpp"
#include "ray-tracing/scene.hpp"
#include "ray-tracing/scene_object.hpp"
#include "ray-tracing/resolution.hpp"
#include "ray-tracing/macroses.hpp"

#include <unordered_map>
#include <memory>
#include <utility>
#include <string>

namespace rt {

class Application {
 public:
  Application();

  int Run();

  void SetResolution(size_t width, size_t height);
  void SetResolution(const Resolution& resolution);
  void SetCameraPosition(double x, double y, double z);
  void SetCameraPosition(const Vector& position);
  void RotateCamera(const Vector& axis, double radian);

  Triangle* CreateTriangle(const std::string& id);
  Sphere* CreateSphere(const std::string& id);
  Light* CreateLight(const std::string& id);
  bool RemoveObject(const std::string& id);

 private:
  Renderer renderer_;
  Image image_;
  Scene scene_;
  Camera camera_;
};

}  // namespace rt

#endif
