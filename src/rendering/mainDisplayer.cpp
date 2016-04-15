#include <mainDisplayer.hpp>

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
            geom::Line line = camera->getRay(x, y);

            bool anyIntersection = false;
            for (const auto& primitive : scene->getObjects()) {
                anyIntersection |= primitive->intersects(line);
            }

            if (anyIntersection) {
                pixels[y * windowWidth * 3 + x * 3 + 0] = 255;
                pixels[y * windowWidth * 3 + x * 3 + 1] = 0;
                pixels[y * windowWidth * 3 + x * 3 + 2] = 0;
            } else {
                pixels[y * windowWidth * 3 + x * 3 + 0] = 255;
                pixels[y * windowWidth * 3 + x * 3 + 1] = 255;
                pixels[y * windowWidth * 3 + x * 3 + 2] = 255;
            }
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_FLOAT, pixels);
    glutSwapBuffers();
}

} // namespace disp
