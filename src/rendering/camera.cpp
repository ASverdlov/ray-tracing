#include <camera.hpp>
#include <iostream>
#include <cassert>

namespace rayt {

Camera::Camera(geom::Point<float> position,
               geom::Transform<float> transform,
               float screenDistance,
               float screenWidth,
               float screenHeight)
    : position(position)
    , transform(transform)
    , screenDistance(screenDistance)
    , screenWidth(screenWidth)
    , screenHeight(screenHeight)
{}

geom::Line<float> Camera::getRay(int screenX, int screenY) {
    auto dir = geom::Point<float>{screenDistance, -screenWidth / 2 + screenX, screenHeight / 2 - screenY};
    return {position, transform * dir};
}

} // namespace rayt
