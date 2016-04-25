#include <mainDisplayer.hpp>
#include <iostream>

namespace disp {

MainDisplayer::MainDisplayer()
    : scene(new rayt::Scene())
    , camera(new rayt::Camera())
{}

MainDisplayer::MainDisplayer(rayt::Scene* scene, rayt::Camera* camera)
    : scene(scene)
    , camera(camera)
{}

void MainDisplayer::display() {
    float* pixels = new float[windowWidth * windowHeight * 3];
    memset(pixels, 0, sizeof(float) * windowHeight * windowWidth * 3);

    for (int x = 0; x < windowWidth; ++x) {
        for (int y = 0; y < windowHeight; ++y) {
            geom::Line<float> line = camera->getRay(x, y);

            rayt::Color intersectionColor = {255, 255, 255};
            for (geom::IPrimitive<float>* primitive : scene->getObjects()) {
                if (primitive->intersects(line)) {
                    intersectionColor = primitive->getColor();
                }
            }
            pixels[y * windowWidth * 3 + x * 3 + 0] = intersectionColor.R;
            pixels[y * windowWidth * 3 + x * 3 + 1] = intersectionColor.G;
            pixels[y * windowWidth * 3 + x * 3 + 2] = intersectionColor.B;
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_FLOAT, pixels);
    glutSwapBuffers();
}

} // namespace disp
