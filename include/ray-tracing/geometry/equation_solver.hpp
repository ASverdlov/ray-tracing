#ifndef EQUATION_SOLVER_HPP
#define EQUATION_SOLVER_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include <exception>
#include <cassert>

namespace rt {

struct Equation {
  double A, B, C;

  Equation() {}
  Equation(double A, double B, double C) : A(A), B(B), C(C) {}

  static const Equation one;
  static const Equation x;

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
    assert(n >= 0 && "Can't exponentiate in negative power");
    if (n == 0) return one;
    if (n == 1) return *this;
    return *this * (*this ^ (n - 1));
  }
};

template<typename OutputIterator>
void Solve(const Equation& equation, OutputIterator output) {
  static const double eps = 1e-13;
  if (std::abs(equation.A) < eps) {
    if (std::abs(equation.B) >= eps) {
      *output++ = -equation.C / equation.B;
    }
    return;
  }
  double square_determinant = equation.B * equation.B -
                              4.0 * equation.A * equation.C;
  if (square_determinant < 0) {
    return;
  }
  double determinant = std::sqrt(square_determinant);
  *output++ = (-equation.B - determinant) * .5 / equation.A;
  *output++ = (-equation.B + determinant) * .5 / equation.A;
}

}  // namespace rt

#endif
