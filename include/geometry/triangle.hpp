#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <primitive.hpp>
#include <plane.hpp>

namespace geom {

template<typename T>
class Triangle : public IPrimitive<T> {
    Triangle() = default;
    Triangle(const std::array<Point, 3>&);

    const std::array<Point, 3> getVertices() const;
    std::array<T, 3> getPlane() const;

    bool intersects(const Line<T>&) const;
    void printLog() const;

private:
    std::array<Point<T>, 3> vertices;
};

template<typename T>
Triangle<T>::Triangle<T>(const std::array<Point<T>, 3>& vertices)
    : vertices(vertices)
{}

template<typename T>
const std::array<Point<T>, 3>& Triangle<T>::getVertices() const {
    return vertices;
}

template<typename T>
Plane<T> Tringle<T>::getPlane() const {
    Transform<T> matrix { {{ vertices[0], vertices[1], vertices[2] }} };
    std::array<T, 3> D {{-1.0, -1.0, -1.0}};
    std::array<T, 3> ABC = matrix.inv() * D;
    return {ABC[0], ABC[1], ABC[2], 1.0};
}

template<typename T>
bool Triangle<T>::intersects(const Line<T>& line) const {
    const Point<T>& s = line.getStart();
    const Point<T>& d = line.getDirection();
    const Plane<T>& plane = getPlane();

    auto equation = SquareEquation<T>{0.0, plane.A * d.x, plane.A * s.x} +
                    SquareEquation<T>{0.0, plane.B * d.y, plane.B * s.y} +
                    SquareEquation<T>{0.0, plane.C * d.z, plane.C * s.z} +
                    SquareEquation<T>{0.0, 0.0, plane.D};
    auto solutions = equation.solve();
    assert(solutions.size() == 1 && "Must be exactly one solution");

    T t = solutions[0];
    Point<T> onPlane = s + d * t;
    //Transform tr{ {{ vertices[0] - onPlane, vertices[1] - onPlane, vertices[2] - onPlane }} };
    //return fabs(tr.det()) < EPS;
}


} // namespace geom

#endif
