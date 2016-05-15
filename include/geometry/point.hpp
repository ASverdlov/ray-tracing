#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <iostream>

namespace rt {

template<typename T>
struct Point {
    bool operator==(const Point<T>&) const;

    Point<T> operator-() const;
    Point<T> operator+(const Point<T>&) const;
    Point<T> operator-(const Point<T>&) const;
    Point<T> operator*(T) const;
    Point<T> operator/(T) const;

    // scalar product
    T operator*(const Point<T>&) const;

    // cross product
    Point<T> operator%(const Point<T>&) const;

    operator std::array<T, 3>();

    T len() const;

    T x, y, z;
};

template<typename T>
bool Point<T>::operator==(const Point<T>& other) const {
    return fabs(x - other.x) < 1e-4 &&
        fabs(y - other.y) < 1e-4 &&
        fabs(z - other.z) < 1e-4;
}

template<typename T>
Point<T> Point<T>::operator-() const {
    return {-x, -y, -z};
}

template<typename T>
Point<T> Point<T>::operator-(const Point<T>& a) const {
    return {x - a.x, y - a.y, z - a.z};
}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& a) const {
    return {x + a.x, y + a.y, z + a.z};
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
Point<T> Point<T>::operator/(T koefficient) const {
    return Point<T>{x / koefficient, y / koefficient, z / koefficient};
}

template<typename T>
T operator*(const std::array<T, 3>& a, const Point<T>& b) {
    return a[0] * b.x + a[1] * b.y + a[2] * b.z;
}

template<typename T>
Point<T> Point<T>::operator%(const Point<T>& other) const {
    return {y * other.z - other.y * z,
            x * other.z - other.x * z,
            x * other.y - other.x * y};
}

template<typename T>
Point<T>::operator std::array<T, 3>() {
    return {{ x, y, z }};
}

} // namespace geom

#endif
