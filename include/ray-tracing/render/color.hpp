#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

namespace rt {

struct Color {
  Color(float r, float g, float b)
    : r(r), g(g), b(b)
  {}
  Color() : Color(0, 0, 0) {}

  float r, g, b;

  Color ApplyBrightness(float brightness) const;

  static const Color red;
  static const Color green;
  static const Color blue;
  static const Color white;

  static const float brightnessBorder;
};

std::ostream& operator<<(std::ostream&, const Color& color);

} // namespace rayt

#endif
