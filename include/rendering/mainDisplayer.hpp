#ifndef MAIN_DISPLAYER_HPP
#define MAIN_DISPLAYER_HPP

#include <renderer.hpp>
#include <scene.hpp>
#include <camera.hpp>
#include <utility.hpp>

namespace rt {

class MainDisplayer : public Displayer {
public:
    MainDisplayer() = delete;
    MainDisplayer(Scene* scene, Camera* camera);

    void display() override;

private:
    Color getPixelColor(size_t x, size_t y) const;

    Scene* scene;
    Camera* camera;
};

} // namespace rt

#endif
