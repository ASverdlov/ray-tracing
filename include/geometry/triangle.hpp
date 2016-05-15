#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <primitive.hpp>
#include <plane.hpp>
#include <cmath>
#include <cassert>
#include <array>

namespace rt {

template<typename T>
class Triangle : public IPrimitive<T> {
public:
    Triangle() = default;
    Triangle(const std::array<Point<T>, 3>&, Color color = Color::red);
    Triangle(const Point<T>&, const Point<T>&, const Point<T>&,
             Color color = Color::red);

    std::array<Point<T>, 3> getVertices() const;
    Point<T> getNormal() const;

    T area() const;

    //bool        intersects(const Line<T>&) const override;
    IntersectionInfo<T> getIntersection(const Line<T>&) const override;
    Color getColor() const override;

private:
    std::array<Point<T>, 3> vertices;
    Color color;
};

template<typename T>
Triangle<T>::Triangle(const std::array<Point<T>, 3>& vertices, Color color)
    : vertices(vertices)
    , color(color)
{}

template<typename T>
Triangle<T>::Triangle(const Point<T>& v1, const Point<T>& v2, const Point<T>& v3, Color color)
    : vertices({v1, v2, v3})
    , color(color)
{}

template<typename T>
std::array<Point<T>, 3> Triangle<T>::getVertices() const {
    return vertices;
}

template<typename T>
T Triangle<T>::area() const {
    return ((vertices[1] - vertices[0]) % (vertices[2] - vertices[0])).len() / 2;
}

template<typename T>
Color Triangle<T>::getColor() const {
    return color;
}

template<typename T>
Point<T> Triangle<T>::getNormal() const {
    Point<T> res = (vertices[1] - vertices[0]) % (vertices[2] - vertices[0]);
    return res / res.len();
}

template<typename T>
IntersectionInfo<T> Triangle<T>::getIntersection(const Line<T>& line) const {
    Point<T> s = line.getStart();
    Point<T> d = line.getDirection();
    Point<T> norm = getNormal();

    T distanceToPlane = (vertices[0] - s) * norm;
    T velocity = d * norm;
    T k = distanceToPlane / velocity;
    Point<T> onPlane = s + d * k;

    IntersectionInfo<T> info;
    if( (((vertices[1] - vertices[0]) % (onPlane - vertices[0])) * norm) <= 0 ||
        (((vertices[2] - vertices[1]) % (onPlane - vertices[1])) * norm) <= 0 ||
        (((vertices[0] - vertices[2]) % (onPlane - vertices[2])) * norm) <= 0) {
        return info;
    }

    info.object = this;
    info.position = onPlane;
    info.distance = k * d.len();
    info.cosinus = fabs(velocity) / d.len();
    return info;
}

} // namespace geom

#endif
