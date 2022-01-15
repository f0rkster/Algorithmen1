#include "uebung10.h"
#include <iostream>
#include <time.h>
#include <math.h>

void shuffleArray(int route[6]) {
    int start = rand() % 6;
    int end = rand() % 6;

    if (start == end)
        shuffleArray(route);
    else {
        int original[6];

        for (int i = 0; i < 6; i++)
            original[i] = route[i];

        if (start > end) {
            int holder = end;
            end = start;
            start = holder;
        }

        for (int i = 0; i <= (end - start); i++) {
            route[start + i] = original[end - i];
        }
    }
}

void simmulatedAnealing()
{
    std::cout << "SIMULATED ANNEALING" << std::endl;
    const int matrixSize = 6;
    int inf = 1024 * 1024 * 1024;
    float e = 2.71828182845904523536;
    int A[matrixSize][matrixSize] =
    {
        {inf,     3,     5,     6,     7,     4},
        {    3, inf,     6,     1,     4,     9},
        {    5,     6, inf,     4,    10,     8},
        {    6,     1,     4, inf,     7,     3},
        {    7,     4,    10,     7, inf,     5},
        {    4,     9,     8,     3,     5, inf}
    };

    float p = 0;
    float tempreture = 100;

    int actualRoute[matrixSize] = { 0 };
    int bestRoute[matrixSize]   = { 0 };

    for (int i = 0; i < matrixSize; i++)
    {
        actualRoute[i] = i;
        bestRoute[i] = i;
    }

    int actualDistance = 0;
    int bestDistance = inf;

    float deltaE = 0;

    float r = 0;
    float epsilon = 1 / (1024 * 104 * 1024);

    srand((unsigned)time(NULL));

    int round = 1;

    for (int i = 0; i < 100; i++)
    {
        int total = 0;
        for (int i = 0; i < matrixSize; i++)
        {
            int node = actualRoute[i];
            int targetNode = i >= matrixSize-1 ? actualRoute[0] : actualRoute[i + 1];

            actualDistance += A[node][targetNode];
        }

        actualDistance += A[actualRoute[matrixSize-1]][actualRoute[0]];

        deltaE = abs(actualDistance - bestDistance) / tempreture;

        p = exp(-deltaE);

        r = ((float)rand() / (RAND_MAX));

        if ((actualDistance < bestDistance) || (r < p))
        {
            for (int i = 0; i < matrixSize; i++)
            {
                bestRoute[i] = actualRoute[i];
            }
            bestDistance = actualDistance;
        }

        if (tempreture <= epsilon)
        {
            return;
        }

        tempreture /= 2;

        actualDistance = 0;

        round++;
        shuffleArray(actualRoute);
    }

    std::cout << "Best Route: [ ";
    for (int i = 0; i < matrixSize; i++)
    {
        std::cout << bestRoute[i] << ", ";
    }
    std::cout << "]" << std::endl;
}