#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include <vector>

void multiplyMatricesWithoutErrors(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int rowsA, int colsA, int colsB);

void multiplyMatricesWithErrors(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int rowsA, int colsA, int colsB);

#endif // MATRIX_MULTIPLICATION_H