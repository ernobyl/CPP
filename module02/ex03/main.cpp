#include "Point.hpp"
#include <iostream>

int main( void )
{
    const Point a(0, 0);
    const Point b(10, 0);
    const Point c(5, 10);
    const Point p(5, 5);

    if (bsp(a, b, c, p) == true)
        std::cout << "Point is inside triangle." << std::endl;
    else
        std::cout << "Point is outside triangle." << std::endl;
    return 0;
}