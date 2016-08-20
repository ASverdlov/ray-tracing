#ifndef APPLICATION_HPP
#define APPLICATION_HPP

// For labeling
#include <unordered_map>
#include <memory>

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

}  // namespace rt

#endif
