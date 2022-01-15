#include "uebung6.h"
#include <iostream>

void LU_decomposition()
{
    std::cout << "LU decompistion:" << std::endl;
    const int n = 4;
    float A[n][n] = {
                                {-1, 1,-1, 1},
                                { 1, 0,-1, 1},
                                { 2, 2, 1,-1},
                                {-2,-1, 1, 1}
    };

    float R[n][n] = {
                                { 0, 0, 0, 0},
                                { 0, 0, 0, 0},
                                { 0, 0, 0, 0},
                                { 0, 0, 0, 0}
    };

    float L[n][n] = {
                                { 1, 0, 0, 0},
                                { 0, 1, 0, 0},
                                { 0, 0, 1, 0},
                                { 0, 0, 0, 1}
    };

    float b[n] = { 1, 2, 3, 4 };

    float x[n] = { 0 };
    float y[n] = { 0 };

    memcpy(R, A, sizeof(A));

    for (int round = 0; round < n; round++)
    {
        for (int row = round + 1; row < n; row++)
        {
            L[row][round] = R[row][round] / R[round][round];
            for (int col = 0; col < n; col++)
            {
                R[row][col] = R[row][col] - L[row][round] * R[round][col];
            }
        }
    }

    // Render Solution L Matrix 
    std::cout << "L Decomposition is as follows..." << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << L[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;


    // Render Solution R Matrix
    std::cout << "R Decomposition is as follows..." << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << R[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // forward substitution
    for (int i = 0; i < n; i++)
    {
        float sum = 0;

        for (int j = 0; j < i; j++)
        {
            sum += L[i][j] * y[j];
        }

        y[i] = (1 / L[i][i]) * (b[i] - sum);
    }

    // render forward substitution
    std::cout << "forward substitution" << std::endl;
    std::cout << "y = [";
    for (int i = 0; i < n; i++)
    {
        std::cout << y[i] << ", ";
    }
    std::cout << "]" << std::endl;

    // reverse substitution
    for (int i = n - 1; i >= 0; i--)
    {
        float sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += R[i][j] * x[j];
        }

        x[i] = (1 / R[i][i]) * (y[i] - sum);
    }

    // render reverse substitution
    std::cout << "reverse substitution" << std::endl;
    std::cout << "x = [";
    for (int i = 0; i < n; i++)
    {
        std::cout << x[i] << ", ";
    }
    std::cout << "]" << std::endl;


}