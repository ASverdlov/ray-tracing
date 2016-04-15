#include <camera.hpp>

namespace rayt {

Camera::Camera(geom::Point position,
               geom::Transform transform,
               float screenDistance,
               float screenWidth,
               float screenHeight)
    : position(position)
    , transform(transform)
    , screenDistance(screenDistance)
    , screenWidth(screenWidth)
    , screenHeight(screenHeight)
{}

geom::Line Camera::getRay(int screenX, int screenY) {
    geom::Point dir = geom::Point{screenDistance, -screenWidth / 2 + screenX, screenHeight / 2 - screenY};
    return geom::Line{position, transform * dir};
}

} // namespace rayt
