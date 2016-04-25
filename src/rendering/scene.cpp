#include <scene.hpp>

namespace rayt {

const std::vector<geom::IPrimitive<float>*>& Scene::getObjects() const {
    return objects;
}

void Scene::addObject(geom::IPrimitive<float>* object) {
    objects.push_back(object);
}

} // namespace rtl
