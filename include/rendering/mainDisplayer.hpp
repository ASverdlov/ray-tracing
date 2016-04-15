#ifndef MAIN_DISPLAYER_HPP
#define MAIN_DISPLAYER_HPP

#include <renderer.hpp>
#include <camera.hpp>
#include <scene.hpp>

namespace disp {

class MainDisplayer : public Displayer {
public:
    void display();

private:
    rayt::Scene* scene;
    rayt::Camera* camera;
};

} // namespace disp

#endif
