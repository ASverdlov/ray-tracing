#include <iostream>

#define TEST_FRIENDS \
    friend class ::matrix_matrixMultipliedByInversedMatrix_Test;
#define TEST_FRIENDS_DEFINITIONS \
    class matrix_matrixMultipliedByInversedMatrix_Test;

#include <geometry/transform.hpp>

// include at the end, because it needs to see
// that operator<< is available for geom::Transform
#include <gtest/gtest.h>

using rt::Transform;

TEST(matrix, matrixMultipliedByInversedMatrix) {
    Transform<float> m(1, 2, 3.11,
                       5, 1, 2.3,
                       -2, 3, 5.5);
    EXPECT_EQ(m * m.inv(), Transform<float>::identity);
}

TEST(matrix, inverseToIdentity) {
    auto m = Transform<float>::identity;
    EXPECT_EQ(m, m.inv());
}

TEST(matrix, multiplyByIdentity) {
    Transform<float> m(1, 2, 3.11,
                       5, 1, 2.3,
                       -2, 3, 5.5);
    EXPECT_EQ(m * Transform<float>::identity, m);
}

TEST(matrix, associativity) {
    Transform<float> m1(2, 5, -2,
                        5, -2, 4,
                        -3.2, 4, 2);
    Transform<float> m2(1, 2, 3.11,
                        5, 1, 2.3,
                        -2, 3, 5.5);
    Transform<float> m3(7, 22, -2.31,
                        -5.6, 0, 7.3,
                        1, 2.3, -20);
    EXPECT_EQ((m1 * m2) * m3, m1 * (m2 * m3));
}

TEST(matrix, determinantOfIdentity) {
    EXPECT_EQ(1.0f, Transform<float>::identity.det());
}

TEST(matrix, determinantOfInversedMatrix) {
    Transform<float> m3(7, 22, -2.31,
                        -5.6, 0, 7.3,
                        1, 2.3, -20);
    EXPECT_EQ(m3.det(), 1 / m3.inv().det());
}
