#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <cassert>
#include <primitive.hpp>
#include <mathematics.hpp>
#include <utility.hpp>

namespace rt {

template<typename T>
class Sphere : public IPrimitive<T> {
public:
    Sphere() = default;
    Sphere(const Point<T>&, T, Color color = Color::red);

    Point<T> getCenter() const;
    T        getRadius() const;

    IntersectionInfo<T> getIntersection(const Line<T>&) const override;
    Color getColor() const override;

private:
    Point<T>    center;
    T           radius;
    Color color;
};

template<typename T>
Sphere<T>::Sphere(const Point<T>& center, T radius, Color color)
    : center(center)
    , radius(radius)
    , color(color)
{}

template<typename T> T        Sphere<T>::getRadius() const { return radius; }
template<typename T> Point<T> Sphere<T>::getCenter() const { return center; }

template<typename T>
Color Sphere<T>::getColor() const {
    return color;
}

template<typename T>
IntersectionInfo<T> Sphere<T>::getIntersection(const Line<T>& line) const {
    /*
     * (x - xc) ^ 2 + (y - yc) ^ 2 + (z - zc) ^ 2 = r ^ 2
     * x(t) = x0 + x1 * t
     * y(t) = y0 + y1 * t
     * z(t) = z0 + z1 * t
     * => (x0 + x1 * t - xc) ^ 2 + (y0 + y1 * t - yc) ^ 2 + (z0 + z1 * t - zc) ^ 2 = r ^ 2
     */
    const Point<T>& s = line.getStart();
    const Point<T>& d = line.getDirection();

    SquareEquation<T> equation = (SquareEquation<T>{0.0, d.x, s.x - center.x} ^ 2) +
        (SquareEquation<T>{0.0, d.y, s.y - center.y} ^ 2) +
        (SquareEquation<T>{0.0, d.z, s.z - center.z} ^ 2) +
        SquareEquation<T>{0.0, 0.0, -radius * radius};

    IntersectionInfo<T> info;
    for (T solution : equation.solve()) {
        T currentDistance = solution * d.len();
        auto currentPosition = s + d * solution;
        auto radiusVector = currentPosition - center;
        auto currentCosinus = (radiusVector * (-d)) / (radius * d.len());

        if (currentDistance <= 0 ||
            currentDistance >= info.distance ||
            currentCosinus <= 0) {
            continue;
        }

        //assert(fabs(radiusVector.len() - radius) < EPS);

        info.object = this;
        info.position = currentPosition;
        info.distance = currentDistance;
        info.cosinus = currentCosinus;
    }
    return info;
}

} // namespace geom

#endif
