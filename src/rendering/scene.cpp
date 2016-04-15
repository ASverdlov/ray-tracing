#include <scene.hpp>

namespace rayt {

const std::vector<geom::IPrimitive*>& Scene::getObjects() const {
    return objects;
}

} // namespace rtl
