#include <scene.hpp>
#include <iostream>

namespace rt {

std::vector<IPrimitive<ftype>*> Scene::getObjects() const {
    return objects;
}

std::vector<Light> Scene::getLightSources() const {
    return lights;
}

void Scene::addObject(IPrimitive<ftype>* object) {
    objects.push_back(object);
}

void Scene::addLight(const Light& light) {
    lights.push_back(light);
}

IntersectionInfo<ftype> Scene::pointsTo(const Line<ftype>& line) const {
    IntersectionInfo<ftype> shortestIntersection;
    for (auto* object : objects) {
        auto currentIntersection = object->getIntersection(line);
        if (currentIntersection.object == nullptr) {
            continue;
        }

        if (currentIntersection.distance < shortestIntersection.distance) {
            shortestIntersection = currentIntersection;
        }
    }
    return shortestIntersection;
}

} // namespace rt
