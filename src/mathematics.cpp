namespace geom {

struct SquareEquation {
    /*
     * A * x^2 + B * x + C = 0
     */
    
    const float eps = 1e-12;

    SquareEquation operator+(const SquareEquation& a) const {
        return SquareEquation{A + a.A, B + a.B, C + a.C};
    }
    SquareEquation operator-(const SquareEquation& a) const {
        return SquareEquation{A - a.A, B - a.A, C - a.C};
    }
    SquareEquation operator*(const SquareEquation& a) const {
        return SquareEquation{A * a.C + C * a.A + B * a.B,
                              B * a.C + C * a.B,
                              C * a.C};
    }
    SquareEquation operator^(int n) const {
        // TODO if (n < 0) throw...
        if (n == 0) return SquareEquation{0.0, 0.0, 1.0};
        if (n == 1) return *this;
        return *this * (*this ^ (n - 1));
    }

    vector<float> solve() const {
        // x1,2 = (-B (+/-) det) / (2 * A)
        float squareDeterminant = B * B - 4.0 * A * C;
        if (squareDeterminant < 0) return vector<float>();
        float determinant = sqrt(squareDeterminant);
        return vector<float>{((-B - determinant) * .5 / A, (-B + determinant) * .5 / A};
    }
    float A, B, C;
};

} // namespace geom
