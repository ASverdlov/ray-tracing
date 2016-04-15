#include <cmath>

#include <geometry.hpp>
#include <mathematics.hpp>

namespace geom {

Point Point::operator-(const Point& a) const { 
    return Point{x - a.x, y - a.y, z - a.z};
}
Point Point::operator+(const Point& a) const { 
    return Point{x + a.x, y + a.y, z + a.z};
} 
float Point::operator*(const Point& a) const {
    return x * a.x + y * a.y + z * a.z;
}
float Point::len() const {
    return sqrt(x * x + y * y + z * z);
}

float operator*(const std::array<float, 3>& a, const Point& b) {
    return a[0] * b.x + a[1] * b.y + a[2] * b.z;
}

Transform::Transform(const std::array<std::array<float, 3>, 3>& matrix)
    : matrix(matrix)
{}
Point Transform::operator*(const Point& a) const {
    return Point{matrix[0] * a, matrix[1] * a, matrix[2] * a};
}
Transform Transform::T() const {
    std::array<std::array<float, 3>, 3> x = {{
            {{matrix[0][0], matrix[1][0], matrix[2][0]}},
            {{matrix[0][1], matrix[1][1], matrix[2][1]}},
            {{matrix[0][2], matrix[1][2], matrix[2][2]}}
    }};
    return Transform(x);
}
//Transform Transform::operator*(const Transform& a) const {
    //Transform TMatrix = T();
    //return {
//}

Line::Line(const Point& start, const Point& direction)
    : start(start)
    , direction(direction)
{}
Point Line::getStart() const { return start; }
Point Line::getDirection() const { return start; }

float Sphere::getRadius() const { return radius; }
Point Sphere::getCenter() const { return center; }

bool Sphere::intersects(const Line& line) const {
    /*
     * (x - xc) ^ 2 + (y - yc) ^ 2 + (z - zc) ^ 2 = r ^ 2
     * x(t) = x0 + x1 * t
     * y(t) = y0 + y1 * t
     * z(t) = z0 + z1 * t
     * => (x0 + x1 * t - xc) ^ 2 + (y0 + y1 * t - yc) ^ 2 + (z0 + z1 * t - zc) ^ 2 = r ^ 2
     */
    Point s = line.getStart();
    Point d = line.getDirection();

    SquareEquation equation = (SquareEquation{0.0, d.x, s.x - center.x} ^ 2) +
                              (SquareEquation{0.0, d.y, s.y - center.y} ^ 2) +
                              (SquareEquation{0.0, d.z, s.z - center.z} ^ 2) +
                              SquareEquation{0.0, 0.0, -radius * radius};
    return !equation.solve().empty();
}

} // namespace geom
