#include "uebung2.h"
#include <iostream>
#include <math.h>
#include <cmath>

void pi()
{
	float sn = 2;


	for (int n = 2; n < 4096; n = 2 * n)
	{
		float s2n = sqrt((sn * sn) / (2 + 2 * sqrt(1 - ((sn * sn) / 4))));

		float PI = n * s2n;

		std::cout << PI << " = PI, wenn n " << n << " ist." << std::endl;

		sn = s2n;
	}
}

int karazuba(int _x, int _y)
{
	int n = 0;
	if (_x > _y)
	{
		n = trunc(log10(_x)) + 1;
	}
	else
	{
		n = trunc(log10(_y)) + 1;
	}

    //int n0 = log2(n);
    int n0 = 2;

    if (n <= n0)
    {
        return _x * _y;
    }
    else
    {
		int k = n / 2;
		int p = _x / pow(10, n / 2);
		int q = _x % (int)pow(10, n / 2);
		int s = _y / pow(10, n / 2);
		int t = _y % (int)pow(10, n / 2);
		int e = q - p;
		int f = t - s;
		int u = karazuba(p, s);
		int v = karazuba(abs(e), abs(f));
		int w = karazuba(q, t);


		if (e > 0 && f > 0 || e < 0 && f < 0)
		{
			int result = u * pow(10, 2 * k) + (u + w - v) * pow(10, k) + w;
			return result;
		}
		else if (e > 0 && f < 0 || e < 0 && f > 0)
		{
			int result = u * pow(10, 2 * k) + (u + w + v) * pow(10, k) + w;
			return result;
		}
    }
}
