#include "uebung5.h"
#include <iostream>

float function(float _x, float _y) {
    return 2 * _y * _x;
}

void EulerCauchyMethod(int _x)
{
    float x0 = 0;
    float y0 = 1;
    float deltaX = 1;
    float y1 = 0;
    float x1 = 0;

    for (int i = 1; i <= _x; i++)
    {
        y1 = function(x0, y0) * deltaX + y0;
        x1 = x0 + deltaX;

        std::cout << i << ". iteration:" << std::endl;
        std::cout << "\t x" << i << " = " << x1 << std::endl;
        std::cout << "\t y" << i << " = " << y1 << std::endl;

        x0 = x1;
        y0 = y1;
    }
}

void RungeKuttaMethod2(int _x)
{
    float x0        = 0;
    float y0        = 1;
    float deltaX    = 1;
    float y1        = 0;
    float x1        = 0;
    float k1i       = 0;
    float k2i       = 0;
    float deltaY    = 0;

    for (int i = 1; i <= _x; i++)
    {
        k1i = function(x0, y0);
        k2i = function(x0 + deltaX, y0 + deltaX * k1i);
        deltaY = (deltaX / 2) * (k1i + k2i);

        x1 = x0 + deltaX;
        y1 = y0 + deltaY;

        std::cout << i << ". iteration:" << std::endl;
        std::cout << "\t x" << i << " = " << x1 << std::endl;
        std::cout << "\t y" << i << " = " << y1 << std::endl;

        x0 = x1;
        y0 = y1;
    }
}

void RungeKuttaMethod4(int _x)
{
    float x0 = 0;
    float y0 = 1;
    float deltaX = 1;
    float y1 = 0;
    float x1 = 0;
    float k1i = 0;
    float k2i = 0;
    float k3i = 0;
    float k4i = 0;
    float deltaY = 0;

    for (int i = 1; i <= _x; i++)
    {
        k1i = function(x0, y0);
        k2i = function(x0 + deltaX, y0 + deltaX * k1i);
        k3i = function(x0 + deltaX / 2, y0 + deltaX + k2i / 2);
        k4i = function(x0 + deltaX, y0 + deltaX * k3i);
        deltaY = (deltaX/6)*(k1i + 2*k2i + 2*k3i + k4i);

        x1 = x0 + deltaX;
        y1 = y0 + deltaY;

        std::cout << i << ". iteration:" << std::endl;
        std::cout << "\t x" << i << " = " << x1 << std::endl;
        std::cout << "\t y" << i << " = " << y1 << std::endl;

        x0 = x1;
        y0 = y1;
    }
}
