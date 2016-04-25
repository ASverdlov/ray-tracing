#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <geometry.hpp>

namespace rayt {

class Scene {
public:
    Scene() = default;

    // non-copyable
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    const std::vector<geom::IPrimitive<float>*>& getObjects() const;

    void addObject(geom::IPrimitive<float>* object);

private:
    std::vector<geom::IPrimitive<float>*> objects;
};

} // namespace rayt

#endif
