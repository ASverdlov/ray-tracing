#include <mainDisplayer.hpp>

namespace disp {

void MainDisplayer::display() {
    float* pixels = new float[windowWidth * windowHeight * 3];
    memset(pixels, 0, sizeof(float) * windowHeight * windowWidth * 3);

#if 0
    for (int y = 0; y < windowHeight / 2; ++y) {
        for (int x = 0; x < windowWidth / 2; ++x) {
            pixels[y * windowWidth * 3 + x * 3 + 0] = 255; // R
            pixels[y * windowWidth * 3 + x * 3 + 1] = 0;   // G
            pixels[y * windowWidth * 3 + x * 3 + 2] = 0;   // B
        }
    }
#else
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
#endif

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_FLOAT, pixels);
    glutSwapBuffers();
}

} // namespace disp
