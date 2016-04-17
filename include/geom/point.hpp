#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

namespace geom {

template<typename T>
struct Point {
    Point<T> operator+(const Point<T>&) const;
    Point<T> operator-(const Point<T>&) const;
    Point<T> operator*(T) const;
    T operator*(const Point<T>&) const;

    T len() const;
    void printLog() const;

    T x, y, z;
};

template<typename T>
Point<T> Point<T>::operator-(const Point<T>& a) const {
    return Point<T>{x - a.x, y - a.y, z - a.z};
}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& a) const {
    return Point<T>{x + a.x, y + a.y, z + a.z};
}

// scalar product
template<typename T>
T Point<T>::operator*(const Point<T>& a) const {
    return x * a.x + y * a.y + z * a.z;
}

// point length
template<typename T>
T Point<T>::len() const {
    return std::sqrt(x * x + y * y + z * z);
}

template<typename T>
Point<T> Point<T>::operator*(T koefficient) const {
    return Point<T>{x * koefficient, y * koefficient, z * koefficient};
}

template<typename T>
void Point<T>::printLog() const {
    std::cout << "Point: " << x << ' ' << y << ' ' << z << '\n';
}

template<typename T>
T operator*(const std::array<T, 3>& a, const Point<T>& b) {
    return a[0] * b.x + a[1] * b.y + a[2] * b.z;
}

} // namespace geom

#endif
