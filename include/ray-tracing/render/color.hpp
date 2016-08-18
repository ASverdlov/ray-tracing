#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

namespace rt {

struct Color {
  static const Color red;
  static const Color green;
  static const Color blue;
  static const Color white;

  static const float brightness_treshold;

  Color() : Color(0, 0, 0) {}
  Color(float r, float g, float b)
    : r(r), g(g), b(b)
  {}

  Color ApplyBrightness(float brightness) const;

  float r, g, b;
};

std::ostream& operator<<(std::ostream&, const Color& color);

} // namespace rayt

#endif
