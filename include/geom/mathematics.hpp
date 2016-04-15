#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

#include <vector>
#include <cmath>

namespace geom {

class SquareEquation {
public:
    /*
     * A * x^2 + B * x + C = 0
     */
    
    static const float eps;

    SquareEquation(float A, float B, float C)
        : A(A), B(B), C(C)
    {}

    SquareEquation operator+(const SquareEquation& a) const {
        return SquareEquation(A + a.A, B + a.B, C + a.C);
    }
    SquareEquation operator-(const SquareEquation& a) const {
        return SquareEquation(A - a.A, B - a.A, C - a.C);
    }
    SquareEquation operator*(const SquareEquation& a) const {
        return SquareEquation(A * a.C + C * a.A + B * a.B,
                              B * a.C + C * a.B,
                              C * a.C);
    }
    SquareEquation operator^(int n) const {
        // TODO if (n < 0) throw...
        if (n == 0) return SquareEquation(0.0, 0.0, 1.0);
        if (n == 1) return *this;
        return *this * (*this ^ (n - 1));
    }

    std::vector<float> solve() const {
        // x1,2 = (-B (+/-) det) / (2 * A)
        float squareDeterminant = B * B - 4.0 * A * C;
        if (squareDeterminant < 0) return std::vector<float>();
        float determinant = std::sqrt(squareDeterminant);

        std::vector<float> res(2);
        res[0] = (-B - determinant) * .5 / A;
        res[1] = (-B + determinant) * .5 / A;
        return res;
    }
private:
    float A, B, C;
};

const float SquareEquation::eps = 1e-12;

} // namespace geom

#endif
