#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

#include <geometry.hpp>
#include <intersection.hpp>
#include <light.hpp>
#include <utility.hpp>

namespace rt {

using std::vector;

class Scene {
public:
    vector<Object*> getObjects() const;
    vector<Light> getLightSources() const;

    void AddObject(Primitive* object);
    void AddLight(const Light&);

    CollisionInfo<ftype> pointsTo(const Line<ftype>& line) const;

private:
    vector<Object*> objects;
    vector<Light> lights;

    DELETE_EVIL_CONSTRUCTORS(Scene);
};

} // namespace rayt

#endif
