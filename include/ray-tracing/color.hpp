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

  void CutExceeding() {
    r = fmin(1., r);
    g = fmin(1., g);
    b = fmin(1., b);
  }

  void operator+=(const Color& other) {
    r += other.r;
    g += other.g;
    b += other.b;
  }

  void operator*=(double x) {
    r *= x;
    g *= x;
    b *= x;
  }

  float r, g, b;
};

/* Basic colors */
static constexpr Color RED(1., 0., 0.);
static constexpr Color GREEN(0., 1., 0.);
static constexpr Color BLUE(0., 0., 1.);
static constexpr Color WHITE(1., 1., 1.);
static constexpr Color BLACK(0., 0., 0.);

/* Unimplemented */
inline std::ostream& operator<<(std::ostream&, const Color& color);

inline Color operator*(const Color& color, double k) {
  Color new_color;
  new_color.r = color.r * k;
  new_color.g = color.g * k;
  new_color.b = color.b * k;
  return new_color;
}

inline Color operator*(double k, const Color& color) {
  return color * k;
}

inline Color operator+(const Color& a, const Color& b) {
  Color new_color;
  new_color.r = a.r + b.r;
  new_color.g = a.g + b.g;
  new_color.b = a.b + b.b;
  return new_color;
}

}  // namespace rt

#endif
