#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>

#include <renderer.hpp>

int main(int argc, char** argv) {
    disp::Displayer displayer;
    displayer.start(argc, argv, 512, 512);

    return 0;
}
