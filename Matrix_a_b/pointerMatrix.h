#pragma once
#include <iostream>

void printNumCallMatrix();

void giveArrayMemory(int size_m, int*** matrix);
void freeArrayMemory(int size_m, int*** matrix);

void inputArray(int size_m, int*** matrix);
void inputArrayBased(int size_m, int*** matrix);

void printArray(int size_m, int*** matrix);

bool checkMainDiagonalMatrix(int size_m, int*** matrix);

int** MatrixMultiply(int size_m, int*** first_matrix, int*** second_matrix);

int** doMatrixZeroDiagonalMultiply(int size_m, int*** first_matrix, int*** second_matrix, int*** third_matrix);