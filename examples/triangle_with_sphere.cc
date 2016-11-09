#include <ray-tracing/application.hpp>
#include <ray-tracing/render.hpp>
#include <ray-tracing/geometry.hpp>

int main(int argc, char** argv) {
  rt::Application app;

  //  Basic parameters
  app.SetWindowResolution(512, 512);
  app.SetCameraPosition(0, 0, 0);

  //  Add Sphere
  rt::Sphere *sphere = app.CreateSphere("sphere");
  sphere->SetPosition(170, -100, 0);
  sphere->SetRadius(58);
  sphere->SetColor(1, 0, 0);

  //  Add Triangle
  rt::Triangle *triangle = app.CreateTriangle("triangle");
  triangle->SetVertices(170, -50, 50,
                        290,   0,  0,
                        290, 330, 10);
  triangle->SetColor(rt::Color::green);

  //  Add Light
  rt::Light *light = app.CreateLight("light");
  light->SetPosition(0, 0, 0);

  return app.Run();
}
