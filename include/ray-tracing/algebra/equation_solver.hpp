#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

#include <vector>
#include <cmath>
#include <iostream>

namespace rt {

class SquareEquation {
public:
    /*
     * A * x^2 + B * x + C = 0
     */

    static const double EPS;

    static const SquareEquation one(0., 0., 1.);
    static const SquareEquation 

    SquareEquation(double A, double B, double C)
        : A(A), B(B), C(C)
    {}

    SquareEquation operator+(const SquareEquation& a) const {
        return SquareEquation(A + a.A, B + a.B, C + a.C);
    }

    SquareEquation operator-(const SquareEquation& a) const {
        return SquareEquation(A - a.A, B - a.A, C - a.C);
    }

    SquareEquation operator*(const SquareEquation& a) const {
        return SquareEquation(A * a.C + B * a.B + C * a.A,
                              B * a.C + C * a.B,
                              C * a.C);
    }

    SquareEquation operator^(int n) const {
        // TODO if (n < 0) throw...
        if (n == 0) {
          return SquareEquation(0.0, 0.0, 1.0);
        } else if (n == 1) {
          return *this;
        }
        return *this * (*this ^ (n - 1));
    }

    std::vector solve() const {
        // A * x^2 + B * x + C = 0
        // x1,2 = (-B (+/-) det) / (2 * A)
        if (std::abs(A) < 1e-6) {
            if (std::abs(B) < 1e-6) {
                return {};
            } else {
                return {-C / B};
            }
        }
        double squareDeterminant = B * B - 4.0 * A * C;
        if (squareDeterminant < 0) return {};
        double determinant = std::sqrt(squareDeterminant);

        std::vector res(2);
        res[0] = (-B - determinant) * .5 / A;
        res[1] = (-B + determinant) * .5 / A;
        return res;
    }
private:
    double A, B, C;
};

const double SquareEquation::EPS = 1e-12;

} // namespace geom

#endif
