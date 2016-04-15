#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include <mainDisplayer.hpp>
#include <scene.hpp>
#include <camera.hpp>

int main(int argc, char** argv) {
    auto* scene = new rayt::Scene();
    auto* camera = new rayt::Camera({0.0f, 0.0f, 0.0f}, // position
                                    geom::Transform{},        // transform
                                    100.0f,               // screenDistance
                                    512, 512);          // screenWidth, screenHeight

    auto* sphere = new geom::Sphere({200.0f, 0.0f, 0.0f}, 58.00f);
    scene->addObject(sphere);

    disp::MainDisplayer displayer(scene, camera);
    displayer.start(argc, argv, 512, 512);
    return 0;
}
