#include <mainDisplayer.hpp>
#include <iostream>

namespace rt {

MainDisplayer::MainDisplayer(Scene* scene, Camera* camera)
    : scene(scene)
    , camera(camera)
{}

Color MainDisplayer::getPixelColor(size_t x, size_t y) const {
    auto ray = camera->getRay(x, y);

    auto cameraIntersection = scene->pointsTo(ray);
    if (cameraIntersection.object == nullptr) {
        return Color::blue;
    }

    ftype brightness = Color::brightnessBorder * 0.20f; // initial brightness
    for (const auto& light : scene->getLightSources()) {
        Line<ftype> lightRay = {light.getPosition(), cameraIntersection.position - light.getPosition()};
        auto lightIntersection = scene->pointsTo(lightRay);

        if (lightIntersection.position == cameraIntersection.position /*&&
        lightIntersection.cosinus > 0.0f*/) {
            ftype squareDistance = lightIntersection.distance * lightIntersection.distance;

#if 0
            if (dynamic_cast<const Triangle<ftype>*>(cameraIntersection.object) != nullptr)
                std::cout << "[Triangle] Brightness addition: " <<
                    std::fixed << 1.0f * lightIntersection.cosinus / squareDistance <<
                    ", lightIntersection.cosinus: " << lightIntersection.cosinus <<
                    std::endl;
            else
                std::cout << "[Sphere] Brightness addition: " <<
                    std::fixed << 1.0f * lightIntersection.cosinus / squareDistance <<
                    ", lightIntersection.cosinus: " << lightIntersection.cosinus <<
                    std::endl;
#endif

            brightness += 1.0f * fabs(lightIntersection.cosinus) / squareDistance;
        }
    }

    Color color = cameraIntersection.object->getColor();
    return color.applyBrightness(brightness);
}

void MainDisplayer::display() {
    ftype* pixels = new ftype[windowWidth * windowHeight * 3];
    memset(pixels, 0, sizeof(ftype) * windowHeight * windowWidth * 3);

    for (size_t x = 0; x < windowWidth; ++x) {
        for (size_t y = 0; y < windowHeight; ++y) {
            Color color = getPixelColor(x, y);
            pixels[y * windowWidth * 3 + x * 3 + 0] = color.r;
            pixels[y * windowWidth * 3 + x * 3 + 1] = color.g;
            pixels[y * windowWidth * 3 + x * 3 + 2] = color.b;
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_FLOAT, pixels);
    glutSwapBuffers();
}

} // namespace disp
