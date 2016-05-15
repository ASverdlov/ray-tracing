#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include <rendering.hpp>
#include <geometry.hpp>
#include <utility.hpp>

using namespace rt;

int main(int argc, char** argv) {
    auto* scene = new Scene();
    auto* camera = new Camera({0.0, 0.0, 0.0},  // position
        Transform<ftype>{},                     // transform
        100.0,                                  // screenDistance
        512, 512);                              // screenWidth, screenHeight

    rt::Light light({0.0, 0.0, 0.0});
    auto* sphere = new Sphere<ftype>({170.0, -100.0, 0.0},  // center
        58.00,                                              // radius
        Color{1.0, 0, 0});                                  // color

    auto* triangle = new Triangle<ftype>({170.0, -50.0, 50.0},  // v0
        {290.0, 0.0, 0.0},                                      // v1
        {290.0, 330.0, 10.0},                                   // v2
        Color::green);                                          // color

    std::cout << "Sphere color: " << sphere->getColor();
    std::cout << "Triangle color: " << triangle->getColor();

    scene->addObject(sphere);
    scene->addObject(triangle);
    scene->addLight(light);

    MainDisplayer displayer(scene, camera);
    displayer.start(argc, argv, 512, 512);

    // TODO: wrap into smart pointers
    delete triangle;
    delete sphere;
    delete camera;
    delete scene;

    return 0;
}
