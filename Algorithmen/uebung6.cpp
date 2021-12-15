#include "uebung6.h"

void LU_decomposition()
{
    const int n = 4;
    float inputArray[n][n] = {
                                {-1, 1,-1, 1},
                                { 1, 0,-1, 1},
                                { 2, 2, 1,-1},
                                {-2,-1, 1, 1}};
    float resultArray[n] = { 1, 2, 3, 4 };

    float x1, x2, x3, x4;
    float LArray[n][n];
    float RArray[n][n];
    float xArray[n] = { x1, x2, x3, x4 };
    float yArray[n];
}
