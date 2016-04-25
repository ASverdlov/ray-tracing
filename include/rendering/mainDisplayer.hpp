#ifndef MAIN_DISPLAYER_HPP
#define MAIN_DISPLAYER_HPP

#include <renderer.hpp>
#include <scene.hpp>
#include <camera.hpp>

namespace disp {

class MainDisplayer : public Displayer {
public:
    MainDisplayer();
    MainDisplayer(rayt::Scene* scene, rayt::Camera* camera);

    void display() override;

private:
    rayt::Scene* scene;
    rayt::Camera* camera;
};

} // namespace disp

#endif
