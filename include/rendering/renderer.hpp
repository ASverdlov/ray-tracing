#ifndef RENDERER_HPP
#define RENDERER_HPP

#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>
#include <string>

#include <utility.hpp>


namespace disp {

class Displayer {
public:
    ~Displayer();
    Displayer();
    explicit Displayer(const Displayer& displayer) = default;

    void setInstance();

    void start(int argc, char** argv, ui32 windowWidth, ui32 windowHeight);
    void setTitle(const std::string& title);

protected:
    static Displayer* instance;

    ui32 windowWidth;
    ui32 windowHeight;
    std::string title;

    //unique_ptr<Scene> scene;

    // glut global functions
    static void displayWrapper();

    // implementation of glut wrappers
    virtual void display();
};

} // namespace display_backend

#endif
