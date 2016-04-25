#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <utility.hpp>
#include <point.hpp>

TEST_FRIENDS_DEFINITIONS;

namespace geom {

template<typename U>
class Transform;

template<typename U>
std::ostream& operator<<(std::ostream&, const geom::Transform<U>&);

template<typename U>
class Transform {
    TEST_FRIENDS;
public:
    Transform();
    Transform(const Transform&);
    Transform(const U*);
    Transform(U, U, U,
              U, U, U,
              U, U, U);

    bool operator==(const Transform&) const;
    Transform operator*(U) const;
    Transform operator/(U) const;
    Transform operator*(const Transform&) const;

    Point<U> operator*(const Point<U>&) const;

    Transform T() const;
    Transform inv() const;
    U det() const;

    friend std::ostream& operator<< <U> (std::ostream&, const Transform&);

    //Transform getXRotation(float angle) const;
    //Transform getYRotation(float angle) const;
    Transform getZRotation(U angle) const;

    const static Transform identity;

private:
    U getMinor(int, int) const;
    U matrix[3][3];
};

template<typename T>
const Transform<T> Transform<T>::identity = {1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1};

template<typename U>
Transform<U>::Transform()
    : matrix{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    }
{}

template<typename U>
Transform<U>::Transform(const Transform<U>& other) {
    memcpy(matrix, other.matrix, 3 * 3 * sizeof(U));
}

template<typename U>
Transform<U>::Transform(const U* data) {
    memcpy(matrix, data, 3 * 3 * sizeof(U));
}

template<typename U>
Transform<U>::Transform(U r11, U r12, U r13,
                        U r21, U r22, U r23,
                        U r31, U r32, U r33)
    : matrix{
        {r11, r12, r13},
        {r21, r22, r23},
        {r31, r32, r33}
    }
{}

template<typename U>
bool Transform<U>::operator==(const Transform<U>& other) const {
    bool areSame = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (fabs(matrix[i][j] - other.matrix[i][j]) >= 1e-4) {
                return false;
            }
        }
    }
    return true;
}

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
Transform<U> Transform<U>::operator*(const Transform<U>& other) const {
    Transform<U> result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

template<typename U>
Point<U> Transform<U>::operator*(const Point<U>& p) const {
    return {matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2] * p.z,
            matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2] * p.z,
            matrix[2][0] * p.x + matrix[2][1] * p.y + matrix[2][2] * p.z};
}

template<typename U>
Transform<U> Transform<U>::T() const {
    return {matrix[0][0], matrix[1][0], matrix[2][0],
            matrix[0][1], matrix[1][1], matrix[2][1],
            matrix[0][2], matrix[1][2], matrix[2][2]};
}

template<typename U>
U Transform<U>::getMinor(int removedX, int removedY) const {
    U rm[4];
    int idx = 0;
    for (int x = 0; x < 3; ++x) if (x != removedX){
        for (int y = 0; y < 3; ++y) if (y != removedY){
            rm[idx++] = matrix[x][y];
        }
    }
    return rm[0] * rm[3] - rm[1] * rm[2];
}

template<typename U>
U Transform<U>::det() const {
    return matrix[0][0] * getMinor(0, 0) +
           -matrix[0][1] * getMinor(0, 1) +
           matrix[0][2] * getMinor(0, 2);
}

template<typename U>
Transform<U> Transform<U>::inv() const {
    if (det() == 0) {
        return identity;
    }
    Transform<U> res;
    for (int x = 0, k = 1; x < 3; ++x) {
        for (int y = 0; y < 3; ++y, k *= -1) {
            res.matrix[y][x] = k * getMinor(x, y);
        }
    }
    return res / det();
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
std::ostream& operator<<(std::ostream& os, const geom::Transform<U>& transform) {
    os << '\n';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << transform.matrix[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

} // namespace geom

#endif
