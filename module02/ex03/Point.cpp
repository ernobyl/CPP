#include "Point.hpp"

/* Constructors */
Point::Point() : x(0), y(0) {}

Point::Point(float xVal, float yVal) : x(xVal), y(yVal) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

/* Assignment operator overload */
Point &Point::operator=(const Point &other)
{
    return (*this);
}

/* Destructor */
Point::~Point() {}

/* Getters for x and y */
Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}