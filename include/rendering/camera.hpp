#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry.hpp>

namespace rayt {


class Camera {
public:
    Camera() = default;
    Camera(geom::Point<float> position,
           geom::Transform<float> transform,
           float screenDistance = 5.0,
           float screenWidth = 512.0,
           float screenHeight = 512.0);

    geom::Line<float> getRay(int screenX, int screenY);

private:
    geom::Point<float> position;
    geom::Transform<float> transform;
    float screenDistance;
    float screenWidth;
    float screenHeight;
};

} // namespace rayt

#endif
