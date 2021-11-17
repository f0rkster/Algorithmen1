#include "uebung3.h"
#include <math.h>
#include <iostream>

int function(int _x)
{
    return pow(_x, 2);
}

void rectangleMethod(float _a, float _b, float _i)
{
	float lowerSum = 0;
	float upperSum = 0;
	for (float k = _a; k <= _b; k += _i)
	{
		lowerSum += function(k) * _i;
		upperSum += function(k + _i) + _i;
	}

	std::cout << "Rectangel = " << (lowerSum + upperSum)/2 << std::endl;
}

void trapezoidMethod(float _a, float _b, float _i)
{
}

void simpsonMethod(float _a, float _b, float _i)
{
}
