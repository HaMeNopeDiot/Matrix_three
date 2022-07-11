#include "pointerMatrix.h"

void giveArrayMemory(int size_m, int*** matrix)
{
    (*matrix) = new int* [size_m];
    for (int i = 0; i < size_m; i++)
    {
        (*matrix)[i] = new int[size_m];
    }
}

void freeArrayMemory(int size_m, int*** matrix)
{
    if (*matrix != nullptr)
    {
        for (int i = 0; i < size_m; i++)
        {
            delete[](*matrix)[i];
            (*matrix)[i] = nullptr;
        }
    }
    delete[] * matrix;
    *matrix = nullptr;
}

void inputArray(int size_m, int*** matrix)
{
    if (*matrix != nullptr)
    {
        printNumCallMatrix();
        for (int i = 0; i < size_m; i++)
        {
            std::cout << i + 1 << " line:";
            for (int j = 0; j < size_m; j++)
            {
                int digit;
                std::cin >> digit;
                (*matrix)[i][j] = digit;
            }
        }
    }
}


void inputArrayBased(int size_m, int*** matrix)
{
    int jija = 1;
    if (*matrix != nullptr)
    {
        printNumCallMatrix();
        for (int i = 0; i < size_m; i++)
        {
            for (int j = 0; j < size_m; j++)
            {
                (*matrix)[i][j] = jija++;
            }
            std::cout << '\n';
        }
    }
}

void printArray(int size_m, int*** matrix)
{
    if (*matrix != nullptr)
    {
        for (int i = 0; i < size_m; i++)
        {
            std::cout << i + 1 << " line:";
            for (int j = 0; j < size_m; j++)
            {
                std::cout << (*matrix)[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

void printNumCallMatrix()
{
    static int count_calls = 0;
    std::cout << "Input matrix " << ++count_calls << '\n';
}

bool checkMainDiagonalMatrix(int size_m, int*** matrix)
{
    if (*matrix != nullptr)
    {
        bool flag = false;
        int count_zeroes = 0;
        for (int i = 0; i < size_m; i++)
        {
            if ((*matrix)[i][i] == 0)
            {
                count_zeroes++;
                if (count_zeroes >= 2)
                    return false;
            }
        }

        return (bool)count_zeroes;
    }
    else
    {
        return false;
    }
}

int** MatrixMultiply(int size_m, int*** first_matrix, int*** second_matrix)
{
    int** new_matrix = nullptr;
    if (*first_matrix != nullptr && *second_matrix != nullptr)
    {
        giveArrayMemory(size_m, &new_matrix);
        for (int i = 0; i < size_m; i++)
        {
            for (int j = 0; j < size_m; j++)
            {
                int sum = 0;
                for (int k = 0; k < size_m; k++)
                {
                    sum += (*first_matrix)[i][k] * (*second_matrix)[k][j];
                }
                new_matrix[i][j] = sum;

            }
        }
    }
    return new_matrix;
}

int** doMatrixZeroDiagonalMultiply(int size_m, int*** first_matrix, int*** second_matrix, int*** third_matrix)
{
    int** fouth_matrix = nullptr;
    if (checkMainDiagonalMatrix(size_m, first_matrix) && checkMainDiagonalMatrix(size_m, second_matrix))
    {
        fouth_matrix = MatrixMultiply(size_m, first_matrix, second_matrix);
    }
    if (checkMainDiagonalMatrix(size_m, third_matrix) && checkMainDiagonalMatrix(size_m, second_matrix))
    {
        fouth_matrix = MatrixMultiply(size_m, third_matrix, second_matrix);
    }
    if (checkMainDiagonalMatrix(size_m, first_matrix) && checkMainDiagonalMatrix(size_m, third_matrix))
    {
        fouth_matrix = MatrixMultiply(size_m, first_matrix, third_matrix);
    }
    return fouth_matrix;
}