#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include <cmath>

namespace rt {

struct Color {
  static const Color red;
  static const Color green;
  static const Color blue;
  static const Color white;
  static const Color black;

  Color() : Color(0, 0, 0) {}
  Color(float r, float g, float b)
    : r(r), g(g), b(b)
  {}

  Color& ApplyBrightness(float brightness) {
    r = fmin(1., r * brightness);
    g = fmin(1., g * brightness);
    b = fmin(1., b * brightness);
    return *this;
  }

  float r, g, b;
};

std::ostream& operator<<(std::ostream&, const Color& color);

}  // namespace rt

#endif
