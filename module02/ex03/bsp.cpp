#include "Fixed.hpp"
#include "Point.hpp"

Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
    return Fixed ((p1.getX() * (p2.getY() - p3.getY()) +
                    p2.getX() * (p3.getY() - p1.getY()) +
                    p3.getX() * (p1.getY() - p2.getY())) / 2.0f);
}