#include "uebung9.h"
#include <math.h>
#include <iostream>


float func(float _x) {
	return 3*_x*_x+2*_x;
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

float round2(float _var){
	float value = (int)(_var * 100 + .5);
	return (float) value / 100;
}

void gradientMethod()
{
	std::cout << "GRADIENT" << std::endl;
	float interval = 0.005;
	float h = 0.00001;
	float start = -5;
	float min = 0;
	int count = 1;

	if (derivation(start, h) == 0)
	{
		min = start;
	}
	else if (derivation(start, h) < 0)
	{
		setDeltaPositiv(&interval);
	}
	else if (derivation(start, h) > 0)
	{
		setDeltaNegativ(&interval);
	}

	while (abs(derivation(start, h)) > 0.05)
	{
		count++;
		start += interval;
	}

	min = start;

	std::cout << "Minimum = " << round2(min) << std::endl;
	std::cout << "It need's " << count << " iterations" << std::endl;
}
