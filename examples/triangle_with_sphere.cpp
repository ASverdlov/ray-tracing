#include <rendering.hpp>
#include <geometry.hpp>

using namespace rt;

// Sphere model
unique_ptr<Sphere> CreateSphere() {
  unique_ptr<Sphere> sphere(new Sphere());
  sphere->SetPosition(170, -100, 0);
  sphere->SetRadius(58);
  sphere->SetColor(1, 0, 0);
  return sphere;
}

// Triangle model
unique_ptr<Triangle> CreateTriangle() {
  unique_ptr<Triangle> triangle(new Triangle());
  triangle->SetVertices(170, -50, 50,
                        290,   0,  0,
                        290, 330, 10);
  triangle->SetColor(Color::green);
  return triangle;
}

int main(int argc, char** argv) {
  Application app;
  
  // Set up window resolution
  app.window.SetResolution(512, 512);

  // Attach needed entities to scene
  app.scene.AddModel(CreateSphere());
  app.scene.AddModel(CreateTriangle());
  app.scene.AddLight(Light(0, 0, 0));

  // Camera entity
  unique_ptr<Camera> camera(new Camera());
  camera->SetPosition(0, 0, 0);
  camera->SetDistance(100);
  camera->SetShape(512, 512);
  app.scene.SetCamera(camera);

  return app.Run();
}
