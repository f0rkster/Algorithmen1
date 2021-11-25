#include "uebung1.h"
#include "uebung2.h"
#include "uebung3.h"
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

    return 0;
}