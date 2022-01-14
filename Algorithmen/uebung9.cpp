#include "uebung9.h"
#include <math.h>
#include <iostream>

float func(float _x) {
	return _x*_x;
}

float derivation(float _x, float _h) {
	return (func(_x + _h) - func(_x)) / _h;
}

void setDeltaNegativ(float* _delta)
{
	if (*_delta > 0)
	{
		*_delta *= -1;
	}
}

void setDeltaPositiv(float* _delta)
{
	if (*_delta < 0)
	{
		*_delta *= -1;
	}
}

void gradientMethod()
{
	std::cout << "GRADIENT" << std::endl;
	float interval = 0.05;
	float h = 0.00001;
	float start = -5;
	float min = 0;
	float delta = 0.0001;

	if (derivation(start, h) == 0)
	{
		min = h;
	}
	else if (derivation(start, h) < 0)
	{
		setDeltaNegativ(&delta);
	}
	else if (derivation(start, h) > 0)
	{
		setDeltaPositiv(&delta);
	}

	while (abs(derivation(start, h)) > 0.000000005)
	{
		start += delta;
	}

	min = start;

	std::cout << "Minimum = " << min << std::endl;

}
