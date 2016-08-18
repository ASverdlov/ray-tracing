#ifndef EQUATION_SOLVER_HPP
#define EQUATION_SOLVER_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include <exception>

namespace rt {

struct Equation {
  double A, B, C;

  static const Equation one(0, 0, 1);
  static const Equation x(0, 1, 0);

  Equation operator+(const Equation& rhs) const {
    return Equation(A + rhs.A, B + rhs.B, C + rhs.C);
  }
  Equation operator-(const Equation& rhs) const {
    return Equation(A - rhs.A, B - rhs.A, C - rhs.C);
  }
  Equation operator*(const Equation& rhs) const {
    return Equation(A * rhs.C + B * rhs.B + C * rhs.A,
                    B * rhs.C + C * rhs.B,
                    C * rhs.C);
  }
  Equation operator^(int n) const {
    if (n < 0) throw std::logic_error("Can't exponentiate in negative power");
    if (n == 0) return one;
    if (n == 1) return *this;
    return *this * (*this ^ (n - 1));
  }
};

template<typename OutputIterator>
void Solve(const Equation& equation, OutputIterator output) {
  static const double eps = 1e-13;
  if (abs(equation.A) < eps) {
    if (abs(equation.B) >= eps) {
      *output++ = -equation.C / equation.B;
    }
    return;
  }
  double square_determinant = B * B - 4.0 * A * C;
  if (square_determinant < 0) {
    return;
  }
  double determinant = std::sqrt(square_determinant);
  *output++ = (-B - determinant) * .5 / A;
  *output++ = (-B + determinant) * .5 / A;
}

} // namespace geom

#endif
