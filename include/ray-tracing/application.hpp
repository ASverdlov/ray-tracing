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
#include "ray-tracing/entity.hpp"

namespace rt {

class Application {
 public:
  typedef std::string Label;

  void Run();

  void SetWindowResolution(int width, int height);
  void SetWindowResolution(const Resolution& resolution);
  void SetCameraPosition(double x, double y, double z);
  void SetCameraPosition(const Vector& position);
  void RotateCamera(const Vector& axis, double radian);

  Triangle* CreateTriangle(const Label& label);
  Sphere* CreateSphere(const Label& label);
  Light* CreateLight(const Label& label);

  bool RemoveEntity(const Label& label);

 private:
  typedef std::unordered_map<Label, std::unique_ptr<Entity>> EntityStorage;

  Renderer renderer_;
  Window window_;
  Scene scene_;

  EntityStorage storage;

  template<typename Entity>
  Entity* CreateEntity(const Label& label);
};

template<typename Entity>
Entity* Application::CreateEntity(const Label& label) {
  auto entity = std::make_unique<Entity>();
  auto insertion_result = storage.emplace(label, std::move(entity));

  auto pointer_to_entity = insertion_result.first->second.get();
  bool was_inserted = insertion_result.second;

  return was_inserted ? static_cast<Entity*>(pointer_to_entity) : nullptr;
}

bool Application::RemoveEntity(const Application::Label& label) {
  return storage.erase(label) > 0;
}

}  // namespace rt

#endif
