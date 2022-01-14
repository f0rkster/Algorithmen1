#include "uebung7.h"
#include <iostream>
#include <math.h>

const int g_MatrixSize = 3;

bool diagonalDominanceCheck(float _matrix[g_MatrixSize][g_MatrixSize])
{
	float sum = 0;
	for (int i = 0; i < g_MatrixSize; i++)
	{
		for (int j = 0; j < g_MatrixSize; j++)
		{
			sum += _matrix[i][j] - 2 * _matrix[i][i];
		}
	}
	
	return sum < 0 ? true : false;
}

void jacobi()
{
	std::cout << "JACOBI" << std::endl;

	float a[g_MatrixSize][g_MatrixSize] = { {3,1,0},{1,3,1},{0,1,3} };
	float b[g_MatrixSize] = { 1, 5, 7 };
	float x0[g_MatrixSize] = { 0, 0, 0 };
	float x[g_MatrixSize] = { 0, 0 ,0 };
	int count = 0;

	do
	{
		count ++;
		memcpy(x0, x, sizeof(x0));
		if (diagonalDominanceCheck(a))
		{
			for (int i = 0; i < g_MatrixSize; i++)
			{
				float sum = 0;

				for (int j = 0; j < g_MatrixSize; j++)
				{
					if (i != j)
					{
						sum += a[i][j] * x0[j];
					}
				}
				x[i] = (1 / a[i][i]) * (b[i] - sum);
			}
		}

	} while (abs(x[0] - x0[0]) > 0.00000001);

	for (int i = 0; i < g_MatrixSize; i++)
	{
		std::cout << "x" << i << " = " << x[i] << std::endl;
	}
	std::cout << "It need's " << count << " iterations" << std::endl;
}

void gaussSeidel()
{
	std::cout << "GAUSS-SEIDEL" << std::endl;

	float a[g_MatrixSize][g_MatrixSize] = { {3,1,0},{1,3,1},{0,1,3} };
	float b[g_MatrixSize] = { 1, 5, 7 };
	float x0[g_MatrixSize] = { 0, 0, 0 };
	float x[g_MatrixSize] = { 0, 0 ,0 };
	int count = 0;

	do
	{
		count++;
		memcpy(x0, x, sizeof(x0));
		if (diagonalDominanceCheck(a))
		{
			for (int k = 0; k < g_MatrixSize; k++)
			{
				float sum1 = 0;
				for (int i = 0; i < k; i++)
				{
					sum1 += a[k][i] * x[i];
				}
				float sum2 = 0;
				for (int i = k+1; i < g_MatrixSize; i++)
				{
					sum2 += a[k][i] * x[i];
				}


				x[k] = (1 / a[k][k]) * (b[k] - sum1 - sum2);
			}
		}
	} while (abs(x[0] - x0[0]) > 0.00000001);

	for (int i = 0; i < g_MatrixSize; i++)
	{
		std::cout << "x" << i << " = " << x[i] << std::endl;
	}
	std::cout << "It need's " << count << " iterations" << std::endl;
}
