#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <unordered_map>
#include <memory>
#include <utility>
#include <string>

#include "ray-tracing/render.hpp"
#include "ray-tracing/scene.hpp"
#include "ray-tracing/geometry.hpp"
#include "ray-tracing/utility.hpp"
#include "ray-tracing/object.hpp"

namespace rt {

class Application {
 public:
  typedef std::string ID;

 public:
  Application() {
    scene_.SetCamera(&camera_);
  }

  int Run();

  void SetResolution(size_t width, size_t height);
  void SetResolution(const Resolution& resolution);
  void SetCameraPosition(double x, double y, double z);
  void SetCameraPosition(const Vector& position);
  void RotateCamera(const Vector& axis, double radian);

  Triangle* CreateTriangle(const ID& id);
  Sphere* CreateSphere(const ID& id);
  Light* CreateLight(const ID& id);

  bool RemoveObject(const ID& id);

 private:
  typedef std::unordered_map<ID, std::unique_ptr<Object>> ObjectStorage;

  Renderer renderer_;
  Image image_;
  Scene scene_;
  Camera camera_;

  ObjectStorage objects;

  template<typename Object>
  Object* CreateObject(const ID& id);
};

}  // namespace rt

#endif
