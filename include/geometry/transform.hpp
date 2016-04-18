#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <utility.hpp>
#include <array>

namespace geom {

template<typename U>
class Transform {
public:
    Transform();
    Transform(const Transform<U>&) = default;
    Transform(const std::array<std::array<U, 3>, 3>&);
    Transform(U, U, U,
              U, U, U,
              U, U, U);

    Transform<U> operator*(U) const;
    Transform<U> operator/(U) const;
    Point<U> operator*(const Point<U>&) const;

    //Transform operator*(const Transform&) const;
    Transform<U> T() const;
    Transform<U> inv() const;
    U det() const;

    void printLog() const;

    //Transform getXRotation(float angle) const;
    //Transform getYRotation(float angle) const;
    Transform<U> getZRotation(U angle) const;

private:
    U getMinor(ui32 x, ui32 y) const;

    std::array<std::array<U, 3>, 3> matrix;
};

template<typename U>
Transform<U>::Transform()
    : matrix({{
        {{1, 0, 0}},
        {{0, 1, 0}},
        {{0, 0, 1}}
    }})
{}

template<typename U>
Transform<U>::Transform(const std::array<std::array<U, 3>, 3>& matrix)
    : matrix(matrix)
{}

template<typename U>
Transform<U>::Transform(U r11, U r12, U r13,
                        U r21, U r22, U r23,
                        U r31, U r32, U r33)
    : matrix{{ {{r11, r12, r13}},
               {{r21, r22, r32}},
               {{r31, r32, r33}} }}
{}

template<typename U>
Transform<U> Transform<U>::operator*(U koefficient) const {
    return Transform<U>(matrix[0][0] * koefficient, matrix[0][1] * koefficient, matrix[0][2] * koefficient,
                        matrix[1][0] * koefficient, matrix[1][1] * koefficient, matrix[1][2] * koefficient,
                        matrix[2][0] * koefficient, matrix[2][1] * koefficient, matrix[2][2] * koefficient);
}

template<typename U>
Transform<U> Transform<U>::operator/(U koefficient) const {
    return Transform<U>(matrix[0][0] / koefficient, matrix[0][1] / koefficient, matrix[0][2] / koefficient,
                        matrix[1][0] / koefficient, matrix[1][1] / koefficient, matrix[1][2] / koefficient,
                        matrix[2][0] / koefficient, matrix[2][1] / koefficient, matrix[2][2] / koefficient);
}

template<typename U>
Point<U> Transform<U>::operator*(const Point<U>& a) const {
    return Point<U>{matrix[0] * a, matrix[1] * a, matrix[2] * a};
}

template<typename U>
Transform<U> Transform<U>::T() const {
    std::array<std::array<U, 3>, 3> x = {{
            {{matrix[0][0], matrix[1][0], matrix[2][0]}},
            {{matrix[0][1], matrix[1][1], matrix[2][1]}},
            {{matrix[0][2], matrix[1][2], matrix[2][2]}}
    }};
    return Transform<U>(x);
}

template<typename U>
U Transform<U>::getMinor(ui32 removedX, ui32 removedY) const {
    ui32 reducedMatrix[4], idx = 0;
    for (int x = 0; x < 3; ++x) if (x != removedX){
        for (int y = 0; y < 3; ++y) if (y != removedY){
            reducedMatrix[idx++] = matrix[x][y];
        }
    }
    return reducedMatrix[0] * reducedMatrix[3] - reducedMatrix[1] * reducedMatrix[2];
}

template<typename U>
U Transform<U>::det() const {
    return matrix[0][0] * getMinor(0, 0) +
           -matrix[0][1] * getMinor(0, 1) +
           matrix[0][2] * getMinor(0, 2);
}

template<typename U>
Transform<U> Transform<U>::inv() const {
    std::array<std::array<U, 3>, 3> newMatrix;
    for (int x = 0, k = 1; x < 3; ++x) {
        for (int y = 0; y < 3; ++y, k *= -1) {
            newMatrix[x][y] = k * getMinor(x, y);
        }
    }
    return Transform<U>(newMatrix) / det();
}

template<typename U>
Transform<U> Transform<U>::getZRotation(U angle) const {
    return {{{
        {{ std::cos(angle), -std::sin(angle), (U)0.0 }},
        {{ std::sin(angle), std::cos(angle),  (U)0.0 }},
        {{ (U)0.0,          (U)0.0,           (U)1.0 }}
    }}};
}

template<typename U>
void Transform<U>::printLog() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "\n";
    }
}

} // namespace geom

#endif
