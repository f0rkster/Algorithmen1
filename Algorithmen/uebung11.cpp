#include "uebung11.h"
#include <iostream>

//int g_inf = 1024 * 1024 * 1024;
//const int g_matrixSize = 6;
//int g_A[g_matrixSize * g_matrixSize] = { g_inf,     3, g_inf,     6, g_inf,     3,
//                                            3, g_inf,     2,     5,     5,     1,
//                                        g_inf,     2, g_inf,     1,     9,     6,
//                                            6,     5,     1, g_inf,     2,     4,
//                                        g_inf,     5,     9,     2, g_inf,     1,
//                                            3,     1,     6,     4,     1, g_inf };
//int g_usedKnots[g_matrixSize] = { -1 };
//
//struct SConnection
//{
//    int weight = -1;
//    int knot1 = -1;
//    int knot2 = -1;
//};
//
//bool areKnotsAlreadyConnected() {
//    return 0;
//}
//
//bool areAllKnotsTaken() {
//    for (int i = 0; i < g_matrixSize * g_matrixSize; i++)
//    {
//        if (g_A[i] != g_inf)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//int getPsoidoMatrixVariable(int _i, int _j, int* _matrix) {
//    return _matrix[_i * g_matrixSize + _j];
//}
//
//void setPsoidoMatrixVariblesToInfinity(int _i, int _j, int* _matrix) {
//    _matrix[_i * g_matrixSize + _j] = g_inf;
//    _matrix[_j * g_matrixSize + _i] = g_inf;
//}
//
//void setPsoidoMatrixVariblesToInfinity(int _index, int* _matrix) {
//    int i = (_index / g_matrixSize);
//    int j = _index % g_matrixSize;
//
//    _matrix[i * g_matrixSize + j] = g_inf;
//    _matrix[j * g_matrixSize + i] = g_inf;
//}
//
//SConnection* getLowestConnection(int* _matrix) {
//    SConnection result;
//
//    int temp = g_inf;
//
//    for (int i = 0; i < g_matrixSize; i++)
//    {
//        for (int j = 0; j < g_matrixSize; j++)
//        {
//            int newMatrixVariable = getPsoidoMatrixVariable(i, j, _matrix);
//
//            if ((newMatrixVariable < temp) && !areKnotsAlreadyConnected())
//            {
//                temp = newMatrixVariable;
//                result.knot1 = i;
//                result.knot2 = j;
//                result.weight = newMatrixVariable;
//            }
//        }
//    }
//    return &result;
//}

void kruskal()
{
    //std::cout << "KRUSKAL" << std::endl;

    //int temp[g_matrixSize * g_matrixSize];

    //memcpy(temp, g_A, sizeof(g_A));

    //SConnection* connections[g_matrixSize * g_matrixSize];

    //int index = 0;

    ////while (!areAllKnotsTaken())
    ////{
    //SConnection* lConnection = getLowestConnection(temp);
    //connections[index]->knot1 = lConnection->knot1;
    //connections[index]->knot2 = lConnection->knot2;
    //connections[index]->weight = lConnection->weight;
    //setPsoidoMatrixVariblesToInfinity(index, temp);
    //index++;
    ////}

    //for (int i = 0; i < g_matrixSize * g_matrixSize; i++)
    //{
    //    if (connections[i] != nullptr)
    //    {
    //        std::cout << connections[i]->knot1 << ", " << connections[i]->knot2 << ", " << connections[i]->weight << std::endl;
    //    }
    //}


}

void prim()
{
	std::cout << "PRIM" << std::endl;
	int inf = 1024 * 1024 * 1024;
	const int matrixSize = 6;
	int A[matrixSize][matrixSize] = {  {inf,   3, inf,   6, inf,   3},
	                                   {  3, inf,   2,   5,   5,   1},
	                                   {inf,   2, inf,   1,   9,   6},
	                                   {  6,   5,   1, inf,   2,   4},
	                                   {inf,   5,   9,   2, inf,   1},
	                                   {  3,   1,   6,   4,   1, inf}};
	int usedKnots[matrixSize] = { -1 };

	int spanningTree[matrixSize] = { 0 };

	// Wähle einen beliebigen Knoten von G als Startgraph R
	spanningTree[0] = 1;	// A
	std::cout << "0" << std::endl;

	// Solange R noch nicht alle Knoten von G enthält
	for (int r = 0; r < matrixSize-1; r++)
	{
		int besteRoute = inf;
		int tmpJ;
		for (int i = 0; i < matrixSize; i++)
		{
			if (spanningTree[i] == 1)
			{
				for (int j = 0; j < matrixSize; j++)
				{
					if (A[i][j] < besteRoute && spanningTree[j] == 0)
					{
						tmpJ = j;
						besteRoute = A[i][j];
					}
				}
			}
		}
		std::cout << tmpJ << std::endl;
		spanningTree[tmpJ] = 1;
	}

}
