#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <random>

using namespace std;

std::vector<std::vector<int>> generateRandomMatrix(int rows, int cols, std::mt19937& generator)
{
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::uniform_int_distribution<int> distribution(-100, 100);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = distribution(generator);
        }
    }
    return matrix;
}

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

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices_ZeroMatrix)
{
    std::vector<std::vector<int>> A = {
        {0, 0, 0},
        {0, 0, 0}};
    std::vector<std::vector<int>> B = {
        {1, 2},
        {3, 4},
        {5, 6}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices_IdentityMatrix)
{
    std::vector<std::vector<int>> A = {
        {1, 0},
        {0, 1}};
    std::vector<std::vector<int>> B = {
        {2, 3},
        {4, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {2, 3},
        {4, 5}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

TEST(MatrixMultiplicationTest, TestMultiplyMatrices_DiagonalMatrix)
{
    std::vector<std::vector<int>> A = {
        {2, 0, 0},
        {0, 3, 0},
        {0, 0, 4}};
    std::vector<std::vector<int>> B = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);
    std::vector<std::vector<int>> expected = {
        {2, 4, 6},
        {12, 15, 18},
        {28, 32, 36}};
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed!";
}

TEST(MatrixMultiplicationTest, TestGenerateRandomMatrix)
{
    int rows = 3;
    int cols = 3;
    int seed = 42; // Imposta il seed
    std::mt19937 generator(seed);
    std::vector<std::vector<int>> A = generateRandomMatrix(rows, cols, generator);
    std::vector<std::vector<int>> B = generateRandomMatrix(rows, cols, generator);

    // Verifica che la matrice abbia le dimensioni corrette
    ASSERT_EQ(A.size(), rows) << "La matrice dovrebbe avere " << rows << " righe.";
    ASSERT_EQ(A[0].size(), cols) << "La matrice dovrebbe avere " << cols << " colonne.";

    // Verifica che ogni elemento della matrice sia compreso tra -100 e 100
    for (const auto &row : A)
    {
        for (int val : row)
        {
            ASSERT_GE(val, -100) << "Il valore dovrebbe essere >= -100";
            ASSERT_LE(val, 100) << "Il valore dovrebbe essere <= 100";
        }
    }

    std::cout << "Matrice A generata casualmente:" << std::endl;
    for (const auto &row : A)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrice B generata casualmente:" << std::endl;
    for (const auto &row : B)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
