#include <scene.hpp>

namespace rayt {

const std::vector<geom::IPrimitive*>& Scene::getObjects() const {
    return objects;
}

void Scene::addObject(geom::IPrimitive* object) {
    objects.push_back(object);
}

} // namespace rtl
