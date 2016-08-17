#include <render.hpp>
#include <scene.hpp>
#include <window.hpp>

struct Application {
  Renderer renderer;
  Window window;
  Scene scene; 

  void Run();
};
