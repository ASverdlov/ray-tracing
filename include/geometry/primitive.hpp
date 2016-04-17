#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <line.hpp>

namespace geom {

template<typename T>
class IPrimitive {
public:
    virtual bool intersects(const Line<T>& line) const = 0;
    virtual void printLog() const = 0;
};

} // namespace geom

#endif
