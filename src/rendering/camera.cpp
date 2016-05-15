#include <camera.hpp>
#include <iostream>
#include <cassert>

namespace rt {

Camera::Camera(Point<ftype> position,
               Transform<ftype> transform,
               ftype screenDistance,
               ftype screenWidth,
               ftype screenHeight)
    : position(position)
    , transform(transform)
    , screenDistance(screenDistance)
    , screenWidth(screenWidth)
    , screenHeight(screenHeight)
{}

Line<ftype> Camera::getRay(int screenX, int screenY) {
    auto dir = Point<ftype>{screenDistance, -screenWidth / 2 + screenX, screenHeight / 2 - screenY};
    return {position, transform * dir};
}

} // namespace rayt
