#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <geometry.hpp>
#include <intersection.hpp>
#include <light.hpp>
#include <utility.hpp>

namespace rt {

class Scene {
public:
    Scene() = default;

    // non-copyable
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    std::vector<IPrimitive<ftype>*> getObjects() const;
    std::vector<Light> getLightSources() const;

    void addObject(IPrimitive<ftype>* object);
    void addLight(const Light&);

    IntersectionInfo<ftype> pointsTo(const Line<ftype>& line) const;

private:
    std::vector<IPrimitive<ftype>*> objects;
    std::vector<Light> lights;
};

} // namespace rayt

#endif
