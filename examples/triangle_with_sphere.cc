#include <ray-tracing/application.hpp>
#include <ray-tracing/render/renderer.hpp>

using namespace rt;

int main(int argc, char **argv) {
  Application app;

  //  Basic parameters
  //app.SetResolution(1440, 900);
  app.SetResolution(2500, 2000);
  // app.SetCameraPosition(0, 0, 0);

  //  Add Sphere
  Sphere *sphere = app.CreateSphere("sphere");
  sphere->SetPosition(170, 0, 0);
  sphere->SetRadius(28);
  sphere->SetColor(1, 0, 0);

  //  Add Triangle
  Triangle *triangle = app.CreateTriangle("triangle");
  triangle->SetVertices(170, -50, 50,
                        290,   0,  0,
                        290, 330, 10);
  triangle->SetColor(Color::green);

  //  Add Light
  Light *light = app.CreateLight("light");
  light->SetPosition(0, 0, 0);

  return app.Run();
}
