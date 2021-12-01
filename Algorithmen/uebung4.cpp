#include "uebung4.h"
#include <iostream>

void regression()
{
    float year[] = { 1905, 1915, 1925, 1935, 1945, 1955, 1965, 1975, 1985, 1995, 2005 };
    float temp[] = {  7.7,  8.0,  7.9,  8.1,  8.3,  8.1,  7.9,  8.3,  8.5,  9.0,  9.2 };

    float a = 0;
    float b = 0;
    float sumXY = 0;
    float sumX2 = 0;
    float n = sizeof(year) / sizeof(*year);
    float xAverage = 0;
    float yAverage = 0;
    float sumX = 0;
    float sumY = 0;

    for (int i = 0; i < n; i++)
    {
        sumXY += year[i] * temp[i];
        sumX2 += year[i] * year[i];
        sumX += year[i];
        sumY += temp[i];
    }

    xAverage = sumX / n;
    yAverage = sumY / n;

    b = (sumXY - n * xAverage * yAverage) / (sumX2 - n * xAverage * xAverage);
    a = yAverage - b * xAverage;

    std::cout << "Regression: a = " << a << " , b = " << b << std::endl;

}
