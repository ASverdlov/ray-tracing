#ifndef APPLICATION_HPP
#define APPLICAION_HPP

#include <render.hpp>
#include <scene.hpp>
#include <window.hpp>

class Application {
 public:
  void Run();

 private:
  Renderer renderer_;
  Window window_;
  Scene scene_; 
};

#endif
