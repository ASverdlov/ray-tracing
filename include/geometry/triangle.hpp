#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cmath>
#include <primitive.hpp>
#include <plane.hpp>

namespace geom {

template<typename T>
class Triangle : public IPrimitive<T> {
    Triangle() = default;
    Triangle(const std::array<Point<T>, 3>&);
    Triangle(const Point<T>&, const Point<T>&, const Point<T>&);

    const std::array<Point<T>, 3>& getVertices() const;
    Plane<T> getPlane() const;

    T area2() const;
    T area() const;

    bool intersects(const Line<T>&) const;
    void printLog() const;

private:
    bool isInside(const Point<T>&) const;

    std::array<Point<T>, 3> vertices;
};

template<typename T>
Triangle<T>::Triangle(const std::array<Point<T>, 3>& vertices)
    : vertices(vertices)
{}

template<typename T>
Triangle<T>::Triangle(const Point<T>& v1, const Point<T>& v2, const Point<T>& v3)
    : vertices({v1, v2, v3})
{}

template<typename T>
const std::array<Point<T>, 3>& Triangle<T>::getVertices() const {
    return vertices;
}

template<typename T>
Plane<T> Triangle<T>::getPlane() const {
    Transform<T> matrix { {{ vertices[0], vertices[1], vertices[2] }} };
    std::array<T, 3> D {{-1.0, -1.0, -1.0}};
    std::array<T, 3> ABC = matrix.inv() * D;
    return {ABC[0], ABC[1], ABC[2], 1.0};
}

template<typename T>
T Triangle<T>::area2() const {
    return ((vertices[1] - vertices[0]) % (vertices[2] - vertices[0])).len();
}

template<typename T>
T Triangle<T>::area() const {
    return std::sqrt(area2());
}

template<typename T>
bool Triangle<T>::isInside(const Point<T>& point) const {
    T sum1 = area();
    T sum2 = Triangle<T>(vertices[0], vertices[1], point).area() +
             Triangle<T>(vertices[1], vertices[2], point).area() +
             Triangle<T>(vertices[2], vertices[0], point).area();
    return std::abs(sum1 - sum2) < 1e-12;
}

template<typename T>
bool Triangle<T>::intersects(const Line<T>& line) const {
    const Point<T>& s = line.getStart();
    const Point<T>& d = line.getDirection();
    const Plane<T>& plane = getPlane();

    auto equation = SquareEquation<T>{0.0, plane.A * d.x, plane.A * s.x} +
                    SquareEquation<T>{0.0, plane.B * d.y, plane.B * s.y} +
                    SquareEquation<T>{0.0, plane.C * d.z, plane.C * s.z} +
                    SquareEquation<T>{0.0, 0.0,           plane.D};
    auto solutions = equation.solve();
    assert(solutions.size() == 1 && "Must be exactly one solution");

    T t = solutions[0];
    Point<T> onPlane = s + d * t;
    return isInside(onPlane);
}

} // namespace geom

#endif
