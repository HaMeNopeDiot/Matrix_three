#include <iostream>
#include "pointerMatrix.h"

int main()
{
    int size_m;
    std::cout << "Input size of matrix:";
    std::cin >> size_m;

    int** first_matrix = nullptr;
    int** second_matrix = nullptr;
    int** third_matrix = nullptr;
    int** fouth_matrix = nullptr;

    giveArrayMemory(size_m, &first_matrix);
    giveArrayMemory(size_m, &second_matrix);
    giveArrayMemory(size_m, &third_matrix);

    inputArray(size_m, &first_matrix);
    inputArray(size_m, &second_matrix);
    inputArray(size_m, &third_matrix);

    fouth_matrix=doMatrixZeroDiagonalMultiply(size_m, &first_matrix, &second_matrix, &third_matrix);

    printArray(size_m, &fouth_matrix);

    freeArrayMemory(size_m, &first_matrix);
    freeArrayMemory(size_m, &second_matrix);
    freeArrayMemory(size_m, &third_matrix);
    freeArrayMemory(size_m, &fouth_matrix);
    return 0;
}


