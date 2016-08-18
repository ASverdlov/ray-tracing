#ifndef APPLICATION_HPP
#define APPLICAION_HPP

#include <render.hpp>
#include <scene.hpp>
#include <geometry.hpp>
#include <window.hpp>
#include <utility.hpp>

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

  Resolution resolution_;
};

} // namespace rt

#endif
