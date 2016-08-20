#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <unordered_map>
#include <memory>
#include <utility>

#include "render.hpp"
#include "scene.hpp"
#include "geometry.hpp"
#include "window.hpp"
#include "utility.hpp"

namespace rt {

class Application {
 public:
  void Run();

  void SetResolution(int width, int height);
  void SetResolution(const Resolution& resolution);

  Triangle* CreateTriangle(const Label& label);
  Sphere* CreateSphere(const Label& label);
  Light* CreateLight(const Label& label);

  bool RemoveEntity(const Label& label);

 private:
  Renderer renderer_;
  Window window_;
  Scene scene_;

  typedef std::unordered_map<Label, std::unique_ptr<Entity>> EntityStorage;
  EntityStorage storage;

  template<typename Entity>
  Entity* CreateEntity(const Label& label);
};

template<typename Entity>
Entity* Application::CreateEntity(const Label& label) {
  auto entity = std::make_unique<Entity>();
  auto insertion_result = storage.emplace(label, std::move(entity));

  auto iterator = insertion_result.first;
  bool was_inserted = insertion_result.second;

  return was_inserted ? iterator->get() : nullptr;
}

template<typename Entity>
bool Application::RemoveEntity(const Label& label) {
  return storage.erase(label) > 0;
}

}  // namespace rt

#endif
