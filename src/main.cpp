#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include <rendering.hpp>
#include <geometry.hpp>

using namespace rt;

unique_ptr<Scene> CreateScene() {
  unique_ptr<Scene> scene(new Scene());

  // Sphere model
  unique_ptr<Sphere> sphere(new Sphere());
  sphere->SetPosition(170, -100, 0);
  sphere->SetRadius(58);
  sphere->SetColor(1, 0, 0);

  // Triangle model
  unique_ptr<Triangle> triangle(new Triangle());
  triangle->SetVertices(170, -50, 50,
                        290,   0,  0,
                        290, 330, 10);
  triangle->SetColor(Color::green);

  // Light
  Light light(0, 0, 0);

  // Attach objects to the scene
  scene->AddObject(std::move(sphere));
  scene->AddObject(std::move(triangle));
  scene->AddLight(std::move(light));

  return scene;
}

int main(int argc, char** argv) {
  // Scene object
  unique_ptr<Scene> scene = CreateScene();

  // Camera entity
  unique_ptr<Camera> camera(new Camera());
  camera->SetPosition(0, 0, 0);
  camera->SetDistance(100);
  camera->SetResolution(512, 512);
  
  Renderer renderer(std::move(scene), std::move(camera));
  renderer.Run(argc, argv, 512, 512);

  return 0;
}
