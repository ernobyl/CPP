#include "Point.hpp"

static Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed result = (p1.getX() * (p2.getY() - p3.getY()) +
                    p2.getX() * (p3.getY() - p1.getY()) +
                    p3.getX() * (p1.getY() - p2.getY())) / 2;
    return (result < 0 ? result * Fixed(-1) : result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);
    Fixed areaPAB = area(point, a, b);
    Fixed areaPAC = area(point, a, c);
    Fixed areaPBC = area(point, b, c);
    Fixed tolerance = Fixed(0.001f);
    Fixed areaSum = areaPAB + areaPAC + areaPBC;

    // debugging
    std::cout << "Area ABC: " << areaABC << "\n";
    std::cout << "Area PAB: " << areaPAB << "\n";
    std::cout << "Area PAC: " << areaPAC << "\n";
    std::cout << "Area PBC: " << areaPBC << "\n";
    std::cout << "Area Sum: " << areaSum << "\n";

    bool hasSameSign = (areaABC > 0 && areaPAB > 0 && areaPAC > 0 && areaPBC > 0) ||
                       (areaABC < 0 && areaPAB < 0 && areaPAC < 0 && areaPBC < 0);
    if (hasSameSign && (areaSum == areaABC))
        return (true);
    return (false);
}