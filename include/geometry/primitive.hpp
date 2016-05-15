#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <line.hpp>
#include <color.hpp>
#include <point.hpp>
#include <intersection.hpp>

namespace rt {

template<typename T>
class IPrimitive {
public:
    virtual ~IPrimitive() = default;
    virtual Color getColor() const = 0;
    virtual IntersectionInfo<T> getIntersection(const Line<T>& line) const = 0;
};

} // namespace geom

#endif
