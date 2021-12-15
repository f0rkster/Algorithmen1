#include "uebung6.h"
#include <iostream>

void LU_decomposition()
{
    std::cout << "LU decompistion:" << std::endl;
    const int n = 4;
    float input[n][n] = {
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

    float resultArray[n] = { 1, 2, 3, 4 };

    float yArray[n];

    for (int i = 0; i < n; i++)
    {
        R[0][i] = input[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            R[i][k] = input[i][k] - (input[i][0] * input[0][k]) / input[0][0];
        }
    }

    float tempR[n][n];
    memcpy(tempR, R, sizeof(R));
    for (int i = 2; i < n; i++)
    {
        for (int k = 1; k < n; k++)
        {
            R[i][k] = tempR[i][k] - (tempR[i][1] * tempR[1][k]) / tempR[1][1];
        }
    }

    memcpy(tempR, R, sizeof(R));
    for (int i = 3; i < n; i++)
    {
        for (int k = 2; k < n; k++)
        {
            R[i][k] = tempR[i][k] - (tempR[i][2] * tempR[2][k]) / tempR[2][2];
        }
    }







    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            std::cout << R[i][k] << " ";
        }
        std::cout << std::endl;
    }
}
