#ifndef APPLICATION_HPP
#define APPLICAION_HPP

#include <render.hpp>
#include <scene.hpp>
#include <geometry.hpp>
#include <window.hpp>
#include <utility.hpp>

// For labeling
#include <map>
#include <unique_ptr>

namespace rt {

class Application {
 public:
  void Run();

  void SetResolution(int width, int height);
  void SetResolution(const Resolution& resolution);

  Triangle* CreateTriangle(const Label& label);
  Sphere* CreateSphere(const Label& label);
  Light* CreateLight(const Label& label);

  bool RemoveModel(const Label& label);
  bool RemoveLight(const Label& label);

 private:
  Renderer renderer_;
  Window window_;
  Scene scene_; 

  typedef std::map<Label, std::unique_ptr<Model>> ModelStorage;
  typedef std::map<Label, std::unique_ptr<Light>> LightStorage;

  ModelStorage model_storage_;
  LightStorage light_storage_;

  template<typename EntityType, typename StorageType>
  EntityType* CreateEntity(StorageType& storage, const Label& label);
};

} // namespace rt

#endif
