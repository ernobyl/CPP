#include "Point.hpp"

static float area(Point const &p1, Point const &p2, Point const &p3)
{
    Fixed result = (p1.getX() * (p2.getY() - p3.getY()) +
                    p2.getX() * (p3.getY() - p1.getY()) +
                    p3.getX() * (p1.getY() - p2.getY())) / 2;
    return result.toFloat();
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float areaABC = area(a, b, c);
    float areaPAB = area(point, a, b);
    float areaPAC = area(point, a, c);
    float areaPBC = area(point, b, c);

    if (areaABC == areaPAB + areaPAC + areaPBC)
    {
        if ((areaPAB > 0 && areaPAC > 0 && areaPBC > 0) ||
            (areaPAB < 0 && areaPAC < 0 && areaPBC > 0))
            {
                return (true);
            }
    }
    return (false);
}