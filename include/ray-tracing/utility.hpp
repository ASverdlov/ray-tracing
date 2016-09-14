#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cstdlib>
// For model's labeling
#include <string>

#include "geometry/vector.hpp"

typedef uint32_t ui32;

#define STRINGIFY2(X) #X
#define STRINGIFY(X) STRINGIFY2(X)

#ifndef TEST_FRIENDS
#define TEST_FRIENDS
#endif

#ifndef TEST_FRIENDS_DEFINITIONS
#define TEST_FRIENDS_DEFINITIONS
#endif

#define DISABLE_COPYING(ClassName) \
    ClassName(const ClassName&); \
    void operator=(const ClassName&);

namespace rt {

class Placeable {
 public:
  void SetPosition(const Vector& position) { position_ = position; }
  void SetPosition(double x, double y, double z) {
    position_ = Vector(x, y, z);
  }
 private:
  Vector position_;
};

struct Resolution {
  size_t width;
  size_t height;
};

typedef Resolution Size;

}  // namespace rt

#endif
