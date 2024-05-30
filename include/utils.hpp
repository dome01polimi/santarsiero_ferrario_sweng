#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <random>

/**
 * Note: we're placing the implementation of utils methods in this header file
 * because thery are very small.  
*/


/**
    Generate a matrix with random numbers given a generator and an interval of feasible integers.
    @param rows Number of rows of the matrix
    @param cols Number of cols of the matrix
    @param generator Random number generator
    @param lower_bound Minimum feasible integer
    @param upper_bound Maximum feasible integer
*/
std::vector<std::vector<int>> generateRandomMatrix(unsigned rows, unsigned cols, std::mt19937& generator, int lower_bound=-100, int upper_bound=100)
{
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = distribution(generator);
        }
    }
    return matrix;
}

/**
    Generate a random number given a generator.
    @param generator Random number generator
    @param lower_bound Minimum feasible integer
    @param upper_bound Maximum feasible integer
*/
int generateRandomNumber(std::mt19937& generator, int lower_bound=-100, int upper_bound=100)
{
    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);
    return distribution(generator);
}

/**
 * Reference function to check the provided library. 
*/
void multiplyMatricesWithoutErrors(const std::vector<std::vector<int>> &A,
                      const std::vector<std::vector<int>> &B,
                      std::vector<std::vector<int>> &C, int rowsA, int colsA,
                      int colsB) {
  for (int i = 0; i < rowsA; ++i) {
    for (int j = 0; j < colsB; ++j) {
      C[i][j] = 0;
      for (int k = 0; k < colsA; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

#endif