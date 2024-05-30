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

// Suggested command for linux
//
// ./build.sh && ./build/seed_test_multiplication 2> program.stderr 
// ./count_errors.sh program.stderr


constexpr int SEED = 42;
std::mt19937 GENERATOR(SEED);

/**
 * Basic multiplication with a fixed number of rows and cols
 * 
*/
TEST(SeedMatrixMultiplicationTest, SeedMatrixMultiplication_Basic)
{

    unsigned a_rows = 10;
    unsigned a_cols = 20;
    unsigned b_rows = 20;
    unsigned b_cols = 5;
        
    std::vector<std::vector<int>> A = generateRandomMatrix(a_rows, a_cols, GENERATOR);
    std::vector<std::vector<int>> B = generateRandomMatrix(b_rows, b_cols, GENERATOR);

    std::vector<std::vector<int>> C(a_rows, std::vector<int>(b_cols, 0));
    std::vector<std::vector<int>> expected(a_rows, std::vector<int>(b_cols, 0));

    multiplyMatrices(A, B, C, a_rows, a_cols, b_cols);
    multiplyMatricesWithoutErrors(A, B, expected, a_rows, a_cols, b_cols);
    ASSERT_EQ(C, expected) << "Basic Matrix multiplication test failed!";
}

/**
 * Multiply a matrix with a null matrix.
 * Perform Z*B = Z where Z is the all zeros matrix.
 * 
*/
TEST(SeedMatrixMultiplicationTest, SeedMatrixMultiplication_Zero)
{

    unsigned a_rows = 4;
    unsigned a_cols = 5;
    unsigned b_rows = 5;
    unsigned b_cols = 3;
        
    std::vector<std::vector<int>> Z(a_rows, std::vector<int>(a_cols, 0));
    std::vector<std::vector<int>> B = generateRandomMatrix(b_rows, b_cols, GENERATOR);

    std::vector<std::vector<int>> C(a_rows, std::vector<int>(b_cols, 0));
    std::vector<std::vector<int>> expected(a_rows, std::vector<int>(b_cols, 0));

    multiplyMatrices(Z, B, C, a_rows, a_cols, b_cols);
    multiplyMatricesWithoutErrors(Z, B, expected, a_rows, a_cols, b_cols);
    ASSERT_EQ(C, expected) << "Zero Matrix multiplication test failed!";
}

/**
 * Perform a multiplication between a square matrix and the identity matrix.
 * A*I = A;  
*/
TEST(SeedMatrixMultiplicationTest, SeedMatrixMultiplication_Identity)
{

    unsigned a_rows = 4;
    unsigned a_cols = 4;
    unsigned b_rows = 4;
    unsigned b_cols = 4;
        

    std::vector<std::vector<int>> A = generateRandomMatrix(b_rows, b_cols, GENERATOR);
    std::vector<std::vector<int>> I(a_rows, std::vector<int>(a_cols, 0));

    for(unsigned i=0; i<b_rows; i++)
        for(unsigned j=0; j<b_cols; j++)
            if(i==j)
                I[i][j] = 1;

    std::vector<std::vector<int>> C(a_rows, std::vector<int>(b_cols, 0));
    std::vector<std::vector<int>> expected(a_rows, std::vector<int>(b_cols, 0));

    multiplyMatrices(A, I, C, a_rows, a_cols, b_cols);
    multiplyMatricesWithoutErrors(A, I, expected, a_rows, a_cols, b_cols);
    ASSERT_EQ(C, expected) << "Identity Matrix multiplication test failed!";
}

/**
 * Perform a multiplication between two square diagonal matrices.
 * A*B = C;  
*/
TEST(SeedMatrixMultiplicationTest, SeedMatrixMultiplication_Diagonal)
{

    unsigned a_rows = 4;
    unsigned a_cols = 4;
    unsigned b_rows = 4;
    unsigned b_cols = 4;
        

    std::vector<std::vector<int>> A(a_rows, std::vector<int>(a_cols, 0));
    std::vector<std::vector<int>> B(a_rows, std::vector<int>(b_cols, 0));

    for(unsigned i=0; i<a_rows; i++)
        for(unsigned j=0; j<a_cols; j++)
            if(i==j){
                A[i][j] = generateRandomNumber(GENERATOR);
                B[i][j] = generateRandomNumber(GENERATOR);
            }

    std::vector<std::vector<int>> C(a_rows, std::vector<int>(b_cols, 0));
    std::vector<std::vector<int>> expected(a_rows, std::vector<int>(b_cols, 0));

    multiplyMatrices(A, B, C, a_rows, a_cols, b_cols);
    multiplyMatricesWithoutErrors(A, B, expected, a_rows, a_cols, b_cols);
    ASSERT_EQ(C, expected) << "Diagonal Matrix multiplication test failed!";
}

