#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry.hpp>
#include <utility.hpp>

namespace rt {

class Camera {
public:
    Camera() = default;
    Camera(Point<ftype> position,
           Transform<ftype> transform,
           ftype screenDistance = 5.0,
           ftype screenWidth = 512.0,
           ftype screenHeight = 512.0);

    Line<ftype> getRay(int screenX, int screenY);

private:
    Point<ftype> position;
    Transform<ftype> transform;
    ftype screenDistance;
    ftype screenWidth;
    ftype screenHeight;
};

} // namespace rayt

#endif
