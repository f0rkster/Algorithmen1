#include "uebung1.h"
#include <iostream>
#include <math.h>

void route(float _a, int _n)
{
    float result = 0;
    
    float xOld = 0;
    float xNew = 1;

    while (abs(xOld-xNew) > 0.001)
    {
        xOld = xNew;
        xNew = (xOld + _a / xOld) / _n;
    }
    
    result = xNew;

    std::cout << "Die " << _n << "-te Wurzel aus " << _a << " ist " << result << "." << std::endl;
}

void prime(int _n)
{
    std::cout << "Die Primzahlen von 1 bis " << _n << " lauten" << std::endl;

    int *arr = new int[_n];

    for (int i = 0; i < _n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i < (int)sqrt(_n); i++)
    {
        for (int k = 2; k < (_n/i); k++)
        {
            if (i*k<_n)
            {
                arr[i * k] = -1;
            }
        }
    }

    for (int i = 2; i < _n; i++)
    {
        if (arr[i] != -1)
        {
            std::cout << arr[i] << std::endl;
        }
    }
}



