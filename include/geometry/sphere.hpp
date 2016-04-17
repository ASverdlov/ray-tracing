#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <primitive.hpp>
#include <mathematics.hpp>

namespace geom {

template<typename T>
class Sphere : public IPrimitive<T> {
public:
    Sphere() = default;
    Sphere(const Point<T>&, T);

    Point<T> getCenter() const;
    T getRadius() const;

    bool intersects(const Line<T>&) const;
    void printLog() const;

private:
    Point<T> center;
    T        radius;
};

template<typename T>
Sphere<T>::Sphere(const Point<T>& center, T radius)
    : center(center)
    , radius(radius)
{}

template<typename T> T        Sphere<T>::getRadius() const { return radius; }
template<typename T> Point<T> Sphere<T>::getCenter() const { return center; }

template<typename T>
bool Sphere<T>::intersects(const Line<T>& line) const {
    /*
     * (x - xc) ^ 2 + (y - yc) ^ 2 + (z - zc) ^ 2 = r ^ 2
     * x(t) = x0 + x1 * t
     * y(t) = y0 + y1 * t
     * z(t) = z0 + z1 * t
     * => (x0 + x1 * t - xc) ^ 2 + (y0 + y1 * t - yc) ^ 2 + (z0 + z1 * t - zc) ^ 2 = r ^ 2
     */
    Point<T> s = line.getStart();
    Point<T> d = line.getDirection();

    SquareEquation<T> equation = (SquareEquation<T>{0.0, d.x, s.x - center.x} ^ 2) +
                              (SquareEquation<T>{0.0, d.y, s.y - center.y} ^ 2) +
                              (SquareEquation<T>{0.0, d.z, s.z - center.z} ^ 2) +
                              SquareEquation<T>{0.0, 0.0, -radius * radius};
    return !equation.solve().empty();
}

template<typename T>
void Sphere<T>::printLog() const {
    std::cout << "Sphere:\n";
    std::cout << "* radius = " << radius << "\n";
    std::cout << "* center = (" << center.x << ", " << center.y << ")\n\n";
}

} // namespace geom

#endif
