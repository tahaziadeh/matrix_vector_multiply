#include "../MatrixVectorMultiply.hpp"
#include "../MatrixVectorMultiply.cpp"
#include <gtest/gtest.h>

TEST(MatrixVectorMultiplyTests, HappyScenario)
{

    /**
     * Initialize the matrix as follows 
     *  | 1   22   3   3 |
     *  | 1   1   1   17 |
     *  | 1   5   18   1 |
     */

    matrix m;
    m.m[0][0] = 1;
    m.m[0][1] = 22;
    m.m[0][2] = 3;
    m.m[0][3] = 3;
    m.m[1][0] = 1;
    m.m[1][1] = 1;
    m.m[1][2] = 1;
    m.m[1][3] = 17;
    m.m[2][0] = 1;
    m.m[2][1] = 5;
    m.m[2][2] = 18;
    m.m[2][3] = 1;

    /**
     * Initalize the vector
     * | 1 |
     * | 1 |
     * | 1 |
     * | 1 |
     * 
     */
    vector v;
    v.v[0] = 1;
    v.v[1] = 1;
    v.v[2] = 1;
    v.v[3] = 1;

    vector res;
    multiply(m, v, res);

    float firstElement = m.m[0][0] * v.v[0] + m.m[0][1] * v.v[1] + m.m[0][2] * v.v[2] + m.m[0][3] * v.v[3];
    float secondElement = m.m[1][0] * v.v[0] + m.m[1][1] * v.v[1] + m.m[1][2] * v.v[2] + m.m[1][3] * v.v[3];
    float thirdElement = m.m[2][0] * v.v[0] + m.m[2][1] * v.v[1] + m.m[2][2] * v.v[2] + m.m[2][3] * v.v[3];

    EXPECT_FALSE(res.isEmpty) << "Expect to have non empty result";

    EXPECT_EQ(
        firstElement,
        res.v[0])
        << "Expect first element in vector to be " << firstElement;

    EXPECT_EQ(
        secondElement,
        res.v[1])
        << "Expect second element in vector to be " << secondElement;

    EXPECT_EQ(
        thirdElement,
        res.v[2])
        << "Expect third element in vector to be " << thirdElement;
}

TEST(MatrixVectorMultiplyTests, DimensionMismatch)
{

    /**
     * Initialize the matrix as follows 
     *  | 1   22   3  |
     *  | 1   1   1   |
     *  | 1   5   18  |
     *  | 4   0   12  |
     */

    matrix_wrong m;
    m.m[0][0] = 1;
    m.m[0][1] = 22;
    m.m[0][2] = 3;
    m.m[1][0] = 1;
    m.m[1][1] = 1;
    m.m[1][2] = 1;
    m.m[2][0] = 1;
    m.m[2][1] = 5;
    m.m[2][2] = 18;
    m.m[3][0] = 4;
    m.m[3][1] = 0;
    m.m[3][2] = 12;
    /**
     * Initalize the vector
     * | 1 |
     * | 1 |
     * | 1 |
     * | 1 |
     * 
     */
    vector v;
    v.v[0] = 1;
    v.v[1] = 1;
    v.v[2] = 1;
    v.v[3] = 1;

    vector res;
    multiply(m, v, res);

    EXPECT_EQ(true, res.isEmpty);
}
