#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include <vector>

void multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int rowsA, int colsA, int colsB);
std::vector<std::vector<int>> generateRandomMatrix(int rows, int cols, int seed);
// Dichiarazione della funzione
int generateRandomNumber(int seed);

#endif // MATRIX_MULTIPLICATION_H