#include <ray-tracing/application.hpp>

using namespace rt;

int main(int argc, char **argv) {
  Application app;

  //  Basic parameters
  app.SetResolution(1440, 900);
  // app.SetCameraPosition(0, 0, 0);

  //  Add Sphere
  Sphere *sphere = app.CreateSphere("sphere");
  sphere->SetPosition(170, 0, 0);
  sphere->SetRadius(28);
  sphere->SetColor(1, 0, 0);

  //  Add Triangle
  Triangle *triangle = app.CreateTriangle("triangle");
  triangle->SetVertices(370, -30, 30,
                        390,   0,  0,
                        390, 30, 10);
  triangle->SetColor(GREEN);

  //  Add Light
  Light *light = app.CreateLight("light");
  light->SetPosition(0, 0, 0);

  return app.Run();
}
