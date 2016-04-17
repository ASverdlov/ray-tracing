#ifndef LINE_HPP
#define LINE_HPP

#include <point.hpp>

namespace geom {

template<typename T>
class Line {
public:
    Line() = default;
    Line(const Point<T>&, const Point<T>&);

    Point<T> getStart() const;
    Point<T> getDirection() const;

private:
    Point<T> start;
    Point<T> direction;
};

template<typename T>
Line<T>::Line(const Point<T>& start, const Point<T>& direction)
    : start(start)
    , direction(direction)
{}

template<typename T>
Point<T> Line<T>::getStart() const { return start; }

template<typename T>
Point<T> Line<T>::getDirection() const { return direction; }

} // namespace geom

#endif
