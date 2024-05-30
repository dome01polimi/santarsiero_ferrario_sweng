#include "matrix_multiplication.h"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <random>

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
    + Loop over multiple seeds if necessary.

*/


constexpr int SEED = 42;
std::mt19937 GENERATOR(SEED);
/**
 * Basic multiplicaiton with a fixed number of rows and cols
 * 
*/
TEST(SeedMatrixMultiplicationTest, SeedMatrixMultiplication_Basic)
{

    unsigned a_rows = 2;
    unsigned a_cols = 4;
    unsigned b_rows = 4;
    unsigned b_cols = 3;
        
    std::vector<std::vector<int>> A = generateRandomMatrix(a_rows, a_cols, GENERATOR);
    std::vector<std::vector<int>> B = generateRandomMatrix(b_rows, b_cols, GENERATOR);

    std::vector<std::vector<int>> C(a_rows, std::vector<int>(b_cols, 0));
    std::vector<std::vector<int>> expected(a_rows, std::vector<int>(b_cols, 0));

    multiplyMatrices(A, B, C, a_rows, a_cols, b_cols);
    multiplyMatricesWithoutErrors(A, B, expected, a_rows, a_cols, b_cols);
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

