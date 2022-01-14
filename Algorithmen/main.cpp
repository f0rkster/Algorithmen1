#include "uebung1.h"
#include "uebung2.h"
#include "uebung3.h"
#include "uebung4.h"
#include "uebung5.h"
#include "uebung6.h"
#include "uebung7.h"
#include <iostream>

int main()
{
    route(16, 2);
    prime(100);
    pi();
    int result = karazuba(1234, 5678); //7006652
    std::cout << "Karazuba = " << result << std::endl;
    rectangleMethod(0, 2, 4);
    trapezoidMethod(0, 2, 4);
    simpsonMethod(0, 2, 4);
    regression();
    EulerCauchyMethod(4);
    RungeKuttaMethod2(4);
    LU_decomposition();
    jacobi();
    gaussSeidel();

    return 0;
}