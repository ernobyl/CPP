#include "Point.hpp"

/* Constructors */
Point::Point() : _x(0), _y(0) {}

Point::Point(float xVal, float yVal) : _x(xVal), _y(yVal) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

/* Assignment operator overload */
Point &Point::operator=(const Point &other)
{
    return (*this);
}

/* Destructor */
Point::~Point() {}

/* Getters for x and y */
const Fixed &Point::getX() const
{
    return (this->_x);
}

const Fixed &Point::getY() const
{
    return (this->_y);
}