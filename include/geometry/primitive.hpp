#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <line.hpp>
#include <color.hpp>

namespace geom {

template<typename T>
class IPrimitive {
public:
    virtual ~IPrimitive() = default;
    virtual bool intersects(const Line<T>& line) const = 0;
    virtual rayt::Color getColor() const = 0;
};

} // namespace geom

#endif
