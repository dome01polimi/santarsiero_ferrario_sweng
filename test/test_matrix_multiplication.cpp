#include "matrix_multiplication.h"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <random>

using namespace std;

// ######################### Source code of multiplyMatrices in src/matrix_mult

// @TODOS
// 1. Basic functional
// 2. Identity Matrix
// 3. Zero Matrix
// 4. Dimension mismatch
// 5. Symmetry
// 6. Associative
// 7. Distributive
// 8. Large Matrix

// All randomized w.r.t a seed

/*
TEST(MatrixMultiplicationTest, TestMultiplyMatrices)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}
*/

/*
TOTAL ERRORS : 20
Errors discovered :
    Error 6: Result matrix contains a number bigger than 100!
    Error 12: The number of rows in A is equal to the number of columns in B!
    Error 14: The result matrix C has an even number of rows!
    Error 20: Number of columns in matrix A is odd!
REMAING ERRORS : 16
    First of all, we try to search the bug(s) in the multiplyMatrices function.
    So multiply two costant matrices : a Matrix A (3x5) and a Matrix B(5x5), matrix A and B have same value.
    We iterate on v(the value that compose the two matrices at iteration v-th,
    start from v = -20, and iterate it in a for loop, increment v by 1 at each iteration,
    so the loop cycle finishes with value v=20(just for see alghorithm's behaviour) and we check if the results are correct.
*/

/*
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_CostantMatrix)
{
    const int rows_A = 3;
    const int cols_A = 5;
    const int rows_B = 5;
    const int cols_B = 5;

    std::vector<std::vector<int>> A(rows_A, std::vector<int>(cols_A, 0));
    std::vector<std::vector<int>> B(rows_B, std::vector<int>(cols_B, 0));
    std::vector<std::vector<int>> C(rows_A, std::vector<int>(cols_B, 0));
    for (int v = -20; v <= 20; v++)
    {
        // Cicli per costruire la matrice A
        for (int i = 0; i < rows_A; ++i)
        {
            for (int j = 0; j < cols_A; ++j)
            {
                A[i][j] = v;
            }
        }

        // Cicli per costruire la matrice B
        for (int i = 0; i < rows_B; ++i)
        {
            for (int j = 0; j < cols_B; ++j)
            {
                B[i][j] = v;
            }
        }
        multiplyMatrices(A, B, C, rows_A, cols_A, cols_B);
        std::vector<std::vector<int>> expected(rows_A, std::vector<int>(cols_B, 0));
        for (int i = 0; i < rows_A; ++i)
        {
            for (int j = 0; j < cols_B; ++j)
            {
                for (int k = 0; k < cols_A; ++k)
                {
                    expected[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        // If we use ASSERT_EQ, the test will stop at the first error, so we use EXPECT_EQ
        EXPECT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
    }
}
*/
/*# New Errors discovered : 13
Error 1: Element-wise multiplication of ones detected!
Error 2: Matrix A contains the number 7!
Error 3: Matrix A contains a negative number!
Error 4: Matrix B contains the number 3!
Error 5: Matrix B contains a negative number!
Error 8: Result matrix contains zero!
Error 9: Result matrix contains the number 99!
Error 10: A row in matrix A contains more than one '1'!
Error 11: Every row in matrix B contains at least one '0'!
Error 13: The first element of matrix A is equal to the first element of matrix B!
Error 15: A row in matrix A is filled entirely with 5s!
Error 16: Matrix B contains the number 6!
Error 19: Every row in matrix A contains the number 8!
REMAING ERRORS : 3
    So now we try to discover the remaining errors taking into account the newly discovered errors
    and trying to create the two matrices so as not to repeat the same errors, as much as possible.
    In the previous two test cases we test if the number of rows in A and coloumns in B is is both even and odd,
    but we only test the case where the number of coloumns in A and the number of rows in B is odd;
    So now at first we must check if the number of coloumns in A and the number of rows in B is even.
    Secondly we only tested rectangular matrices, we need to test the case where square matrices are present;
    to make things even more general we test the case in which we multiply by an identity matrix, so the matrix is ​​both square and diagonal.
    Let's proceed to multiply a nxn Matrix A and a nxn Identity Matrix B
    (in this test n = 10, so A will contain all the numbers from 1 to 100, but taking into consideration all the previous errors !)
*/

/*
TEST(MatrixMultiplicationTest, TestMultiplyMatrices_IdentityMatrix)
{
    const int n = 10; // value of n
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    // Create Identity Matrix B
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Create Matrix A
    int value = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = value;
            value++;
        }
    }

    multiplyMatrices(A, B, C, n, n, n);
    std::vector<std::vector<int>> expected(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                expected[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // If we use ASSERT_EQ, the test will stop at the first error, so we use EXPECT_EQ
    EXPECT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}
*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices_withoutError)
{
    std::vector<std::vector<int>> A = {
        {2, 0},
        {2, 0},
        {2, 0},
        {2, 0},
        {2, 0}};
    std::vector<std::vector<int>> B = {
        {1, 4, 5},
        {2, 4, 5}};

    std::vector<std::vector<int>> C(5, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 5, 2, 3);
    std::vector<std::vector<int>> expected = {
        {2, 8, 10},
        {2, 8, 10},
        {2, 8, 10},
        {2, 8, 10},
        {2, 8, 10}};
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
