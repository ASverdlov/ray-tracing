#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include <rendering.hpp>
#include <geometry.hpp>

int main(int argc, char** argv) {
    auto* scene = new rayt::Scene();
    auto* camera = new rayt::Camera({0.0f, 0.0f, 0.0f},       // position
                                    geom::Transform<float>{}, // transform
                                    100.0f,                   // screenDistance
                                    512, 512);                // screenWidth, screenHeight

    //auto* sphere = new geom::Sphere<float>({200.0f, 0.0f, 0.0f}, 58.00f);
    auto* triangle = new geom::Triangle<float>({200.0f, -50.0f, 50.0f},
                                               {200.0f, 0.0f, 0.0f},
                                               {200.0f, 33.0f, 10.0f});
    //scene->addObject(sphere);
    scene->addObject(triangle);

    disp::MainDisplayer displayer(scene, camera);
    displayer.start(argc, argv, 512, 512);
    return 0;
}
