#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include <mainDisplayer.hpp>
#include <scene.hpp>
#include <camera.hpp>

int main(int argc, char** argv) {
    auto* sphere = new geom::Sphere({2, 2, 2}, 0.01f);
    auto* scene = new rayt::Scene();
    auto* camera = new rayt::Camera();

    scene->addObject(sphere);
    disp::MainDisplayer displayer(scene, camera);
    displayer.start(argc, argv, 512, 512);

    return 0;
}
