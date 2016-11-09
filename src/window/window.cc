#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include "ray-tracing/window/window.hpp"
#include "ray-tracing/render/frame.hpp"

namespace rt {

void Window::Show(const Frame& frame) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glDrawPixels(resolution_.width, resolution_.height,
      GL_RGB, GL_FLOAT, frame.data());
  glutSwapBuffers();
}

}  // namespace rt
