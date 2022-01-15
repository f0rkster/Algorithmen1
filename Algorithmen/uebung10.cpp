#include "uebung10.h"
#include <iostream>

int g_inf = 1024 * 1024 * 1024;
const int g_matrixSize = 6;
int g_A[g_matrixSize * g_matrixSize] = {g_inf,     3, g_inf,     6, g_inf,     3,
                                            3, g_inf,     2,     5,     5,     1,
                                        g_inf,     2, g_inf,     1,     9,     6,
                                            6,     5,     1, g_inf,     2,     4,
                                        g_inf,     5,     9,     2, g_inf,     1,
                                            3,     1,     6,     4,     1, g_inf};
int g_usedKnots[g_matrixSize] = { -1 };

struct SConnection
{
    int weight = -1;
    int knot1 = -1;
    int knot2 = -1;
};

bool areKnotsAlreadyConnected() {
    return 0;
}

int getPsoidoMatrixVariable(int _i, int _j, int* _matrix) {
    return _matrix[_i * g_matrixSize + _j];
}

void setPsoidoMatrixVariblesToInfinity(int _i, int _j, int* _matrix) {
    _matrix[_i * g_matrixSize + _j] = g_inf;
    _matrix[_j * g_matrixSize + _i] = g_inf;
}

SConnection* getLowestConnection(int* _matrix) {
    SConnection result;

    int temp = g_inf;

    for (int i = 0; i < g_matrixSize; i++)
    {
        for (int j = 0; j < g_matrixSize; j++)
        {
            int newMatrixVariable = getPsoidoMatrixVariable(i, j, _matrix);

            if ((newMatrixVariable < temp) && !areKnotsAlreadyConnected())
            {
                temp = newMatrixVariable;
                result.knot1 = i;
                result.knot2 = j;
                result.weight = newMatrixVariable;
            }
        }
    }
    return &result;
}

void kruskal()
{
    std::cout << "KRUSKAL" << std::endl;

    int temp[g_matrixSize * g_matrixSize];

    memcpy(temp, g_A, sizeof(g_A));

    SConnection* connections[g_matrixSize] = { nullptr };
    
    connections[0] = getLowestConnection(temp);

    g_usedKnots[0] = connections[0]->knot1;
    g_usedKnots[1] = connections[0]->knot2;

    setPsoidoMatrixVariblesToInfinity(connections[0]->knot1, connections[0]->knot2, temp);

    for (int i = 0; i < g_matrixSize; i++)
    {
        for (int j = 0; j < g_matrixSize; j++)
        {
            int newMatrixVariable = getPsoidoMatrixVariable(i, j, temp);

            if (newMatrixVariable > 100) {
                std::cout << "i";
            }
            else
            {
                std::cout << newMatrixVariable;
            }
            std::cout << ", ";
        }

        std::cout << std::endl;
    }


}

void pirm()
{
}
