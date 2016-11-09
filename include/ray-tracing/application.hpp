#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <unordered_map>
#include <memory>
#include <utility>
#include <string>

#include "ray-tracing/render.hpp"
#include "ray-tracing/scene.hpp"
#include "ray-tracing/geometry.hpp"
#include "ray-tracing/window.hpp"
#include "ray-tracing/utility.hpp"
#include "ray-tracing/object.hpp"

namespace rt {



class Application {
 public:
  typedef std::string ID;

  int Run();

  void SetWindowResolution(int width, int height);
  void SetWindowResolution(const Resolution& resolution);
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
  Window window_;
  Scene scene_;

  ObjectStorage objects;

  template<typename Object>
  Object* CreateObject(const ID& id);
};

}  // namespace rt

#endif
