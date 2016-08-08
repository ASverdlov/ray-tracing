#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <utility.hpp>
#include <point.hpp>

TEST_FRIENDS_DEFINITIONS;

namespace rt {

class Transform;

std::ostream& operator<<(std::ostream&, const Transform&);

class Transform {
    TEST_FRIENDS;
public:
    Transform();
    Transform(const Transform&);
    Transform(const double*);
    Transform(double, double, double,
              double, double, double,
              double, double, double);

    bool operator==(const Transform&) const;
    bool operator!=(const Transform&) const;

    Transform operator*(double) const;
    Transform operator/(double) const;
    Transform operator*(const Transform&) const;

    Vec3d operator*(const Vec3d&) const;

    Transform T() const;
    Transform inv() const;
    double det() const;

    friend std::ostream& operator<< <double> (std::ostream&, const Transform&);

    //Transform getXRotation(float angle) const;
    //Transform getYRotation(float angle) const;
    Transform getZRotation(double angle) const;

    const static Transform identity;

private:
    double getMinor(int, int) const;
    double matrix[3][3];
};

const Transform<T> Transform<T>::identity = {1, 0, 0,
                                             0, 1, 0,
                                             0, 0, 1};

Transform::Transform()
    : matrix{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    }
{}

Transform::Transform(const Transform& other) {
    memcpy(matrix, other.matrix, 3 * 3 * sizeof(double));
}

Transform::Transform(const double* data) {
    memcpy(matrix, data, 3 * 3 * sizeof(double));
}

Transform::Transform(double r11, double r12, double r13,
                        double r21, double r22, double r23,
                        double r31, double r32, double r33)
    : matrix{
        {r11, r12, r13},
        {r21, r22, r23},
        {r31, r32, r33}
    }
{}

bool Transform::operator==(const Transform& other) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (fabs(matrix[i][j] - other.matrix[i][j]) >= 1e-4) {
                return false;
            }
        }
    }
    return true;
}

Transform Transform::operator*(double koefficient) const {
    return Transform(matrix[0][0] * koefficient, matrix[0][1] * koefficient, matrix[0][2] * koefficient,
                        matrix[1][0] * koefficient, matrix[1][1] * koefficient, matrix[1][2] * koefficient,
                        matrix[2][0] * koefficient, matrix[2][1] * koefficient, matrix[2][2] * koefficient);
}

Transform Transform::operator/(double koefficient) const {
    return Transform(matrix[0][0] / koefficient, matrix[0][1] / koefficient, matrix[0][2] / koefficient,
                        matrix[1][0] / koefficient, matrix[1][1] / koefficient, matrix[1][2] / koefficient,
                        matrix[2][0] / koefficient, matrix[2][1] / koefficient, matrix[2][2] / koefficient);
}

Transform Transform::operator*(const Transform& other) const {
    Transform result;
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

Vec3d Transform::operator*(const Vec3d& p) const {
    return {matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2] * p.z,
            matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2] * p.z,
            matrix[2][0] * p.x + matrix[2][1] * p.y + matrix[2][2] * p.z};
}

Transform Transform::T() const {
    return {matrix[0][0], matrix[1][0], matrix[2][0],
            matrix[0][1], matrix[1][1], matrix[2][1],
            matrix[0][2], matrix[1][2], matrix[2][2]};
}

double Transform::getMinor(int removedX, int removedY) const {
    double rm[4];
    int idx = 0;
    for (int x = 0; x < 3; ++x) if (x != removedX){
        for (int y = 0; y < 3; ++y) if (y != removedY){
            rm[idx++] = matrix[x][y];
        }
    }
    return rm[0] * rm[3] - rm[1] * rm[2];
}

double Transform::det() const {
    return matrix[0][0] * getMinor(0, 0) +
           -matrix[0][1] * getMinor(0, 1) +
           matrix[0][2] * getMinor(0, 2);
}

Transform Transform::inv() const {
    if (det() == 0) {
        return identity;
    }
    Transform res;
    for (int x = 0, k = 1; x < 3; ++x) {
        for (int y = 0; y < 3; ++y, k *= -1) {
            res.matrix[y][x] = k * getMinor(x, y);
        }
    }
    return res / det();
}

Transform Transform::getZRotation(double angle) const {
    return {{{
        {{ std::cos(angle), -std::sin(angle), (double)0.0 }},
        {{ std::sin(angle), std::cos(angle),  (double)0.0 }},
        {{ (double)0.0,          (double)0.0,           (double)1.0 }}
    }}};
}

std::ostream& operator<<(std::ostream& os, const Transform& transform) {
    os << '\n';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << transform.matrix[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

} // namespace rt
#endif
