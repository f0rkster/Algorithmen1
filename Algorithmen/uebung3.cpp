#include "uebung3.h"
#include <math.h>
#include <iostream>

float function(float _x)
{
    return pow(_x, 2);
}

float deltaX(float _a, float _b, int _n)
{
	return (_b - _a) / _n;
}

void rectangleMethod(float _a, float _b, int _n)
{
	float dX = deltaX(_a, _b, _n);

	float lowerSum = 0;
	float upperSum = 0;
	float middleSum = 0;

	for (float i = _a; i <= _b - dX ; i += dX)
	{
		lowerSum += function(i);
		upperSum += function(i + dX);
	}

	lowerSum *= dX;
	upperSum *= dX;
	middleSum = (lowerSum + upperSum) / 2;

	std::cout << "Rectangel = " << middleSum << std::endl;
}

void trapezoidMethod(float _a, float _b, int _n)
{
	float dX = deltaX(_a, _b, _n);

	float middleSum = 0;
	float sum = 0;
	for (float i = _a + dX; i <= _b - dX; i += dX)
	{
		sum += function(i);
	}

	middleSum = dX * (sum + function(_a) / 2 + function(_b) / 2);

	std::cout << "Trapezoid = " << middleSum << std::endl;
}

void simpsonMethod(float _a, float _b, int _n)
{
	if (_n % 2 != 0) 	std::cout << "Wrong n!!!" << std::endl;
	else
	{
		float dX = deltaX(_a, _b, _n);

		double innerSum = 0;
		int index = 0;

		for (double i = _a; i <= _b; i += dX) {
			if (index == 0 || index == _n) innerSum += function(i);
			else innerSum += (index % 2 == 1 ? 4 : 2) * function(i);

			index++;
		}

		std::cout << "Simpson = " << (dX / 3) * innerSum << std::endl;
	}
}
