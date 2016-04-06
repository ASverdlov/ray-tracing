#include <renderer.hpp>
#include <utility.hpp>

#include <iostream>
#include <sstream>
#include <cmath>

namespace disp {

// initiate global constants
Displayer* Displayer::instance = nullptr;

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
    for (int i = 0; i < windowWidth * windowHeight; ++i) {
        pixels[i] = rand();
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

} // namespace disp
