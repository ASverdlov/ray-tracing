#include <renderer.hpp>
#include <utility.hpp>

#include <iostream>
#include <sstream>
#include <cmath>

namespace rt {

// initiate global constants
Displayer* Displayer::instance = nullptr;

Displayer::~Displayer() {}
Displayer::Displayer()
    : title("Displayer window")
{}

void Displayer::setInstance() {
    instance = this;
}

void Displayer::start(int argc, char** argv, ui32 windowWidth, ui32 windowHeight) {
    setInstance();

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(title.c_str());

    glutDisplayFunc(displayWrapper);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;

    glutMainLoop();
}

void Displayer::display() {
    float* pixels = new float[windowWidth * windowHeight * 3];
    memset(pixels, 0, sizeof(float) * windowHeight * windowWidth * 3);

    for (int y = 0; y < windowHeight / 2; ++y) {
        for (int x = 0; x < windowWidth / 2; ++x) {
            pixels[y * windowWidth * 3 + x * 3 + 0] = 255; // R
            pixels[y * windowWidth * 3 + x * 3 + 1] = 0;   // G
            pixels[y * windowWidth * 3 + x * 3 + 2] = 0;   // B
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(windowWidth, windowHeight, GL_RGB, GL_FLOAT, pixels);
    glutSwapBuffers();
}

void Displayer::setTitle(const std::string& title) {
    this->title = title;
}

// Glut wrappers
void Displayer::displayWrapper() {
    instance->display();
}

} // namespace rt
