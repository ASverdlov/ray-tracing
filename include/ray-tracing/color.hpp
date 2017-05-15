#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <cmath>

namespace rt {

struct Color {
  Color() : Color(0, 0, 0) {}

  constexpr Color(float r, float g, float b)
    : r(r), g(g), b(b)
  {}

  Color& ApplyBrightness(float brightness) {
    r = fmin(1., r * brightness);
    g = fmin(1., g * brightness);
    b = fmin(1., b * brightness);
    return *this;
  }

  void operator+=(const Color& other) {
    r += other.r;
    g += other.g;
    b += other.b;
  }

  float r, g, b;
};

/* Basic colors */
static constexpr Color RED(1., 0., 0.);
static constexpr Color GREEN(0., 1., 0.);
static constexpr Color BLUE(0., 0., 1.);
static constexpr Color WHITE(1., 1., 1.);
static constexpr Color BLACK(0., 0., 0.);

std::ostream& operator<<(std::ostream&, const Color& color);

}  // namespace rt

#endif
