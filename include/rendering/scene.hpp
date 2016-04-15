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

    const std::vector<geom::IPrimitive*>& getObjects() const;

private:
    std::vector<geom::IPrimitive*> objects;
};

} // namespace rayt

#endif
