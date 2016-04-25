#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

#include <vector>
#include <cmath>
#include <iostream>

namespace geom {

template<typename T>
class SquareEquation {
public:
    /*
     * A * x^2 + B * x + C = 0
     */

    static const T EPS;

    SquareEquation(T A, T B, T C)
        : A(A), B(B), C(C)
    {}

    SquareEquation<T> operator+(const SquareEquation<T>& a) const {
        return SquareEquation<T>(A + a.A, B + a.B, C + a.C);
    }
    SquareEquation<T> operator-(const SquareEquation<T>& a) const {
        return SquareEquation<T>(A - a.A, B - a.A, C - a.C);
    }
    SquareEquation<T> operator*(const SquareEquation<T>& a) const {
        return SquareEquation<T>(A * a.C + C * a.A + B * a.B,
                              B * a.C + C * a.B,
                              C * a.C);
    }
    SquareEquation<T> operator^(int n) const {
        // TODO if (n < 0) throw...
        if (n == 0) return SquareEquation<T>(0.0, 0.0, 1.0);
        if (n == 1) return *this;
        return *this * (*this ^ (n - 1));
    }

    std::vector<T> solve() const {
        // A * x^2 + B * x + C = 0
        // x1,2 = (-B (+/-) det) / (2 * A)
        if (std::abs(A) < 1e-6) {
            if (std::abs(B) < 1e-6) {
                return {};
            } else {
                return {-C / B};
            }
        }
        T squareDeterminant = B * B - 4.0 * A * C;
        if (squareDeterminant < 0) return {};
        T determinant = std::sqrt(squareDeterminant);

        std::vector<T> res(2);
        res[0] = (-B - determinant) * .5 / A;
        res[1] = (-B + determinant) * .5 / A;
        return res;
    }
private:
    T A, B, C;
};

template<typename T>
const T SquareEquation<T>::EPS = 1e-12;

} // namespace geom

#endif
