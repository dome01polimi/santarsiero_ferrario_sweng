#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

// @TODOS
/*
    1. Basic functional 
    2. Identity Matrix 
    3. Zero Matrix
    4. Dimension mismatch
    5. Symmetry 
    6. Associative
    7. Distributive
    8. Large Matrix

    All randomized w.r.t a seed

*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices_ZeroMatrix) {
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> B = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices_IdentityMatrix) {
    std::vector<std::vector<int>> A = {
        {1, 0},
        {0, 1}
    };
    std::vector<std::vector<int>> B = {
        {2, 3},
        {4, 5}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {2, 3},
        {4, 5}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

//test on diagonal matrix
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_DiagonalMatrix) {
    std::vector<std::vector<int>> A = {
        {2, 0, 0},
        {0, 3, 0},
        {0, 0, 4}
    };
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);
    std::vector<std::vector<int>> expected = {
        {2, 4, 6},
        {12, 15, 18},
        {28, 32, 36}
    };
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";

//test on inverse matrix

}
