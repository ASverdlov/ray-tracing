#include <primitives.hpp>
#include <mathematics.hpp>

namespace geom {

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

    SquareEquation equation = SquareEquation{0.0, d.x, s.x - center.x} ^ 2 +
                              SquareEquation{0.0, d.y, s.y - center.y} ^ 2 +
                              SquareEquation{0.0, d.z, s.z - center.z} ^ 2 +
                              SquareEquation{0.0, 0.0, -radius * radius};
    return !equation.solve().empty();
}

} // namespace geom
