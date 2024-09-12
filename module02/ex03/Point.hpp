#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		/* Constructors */
		Point();
		Point(float xVal, float yVal);
		Point(const Point &other);
		/* Assignment operator overload */
		Point &operator=(const Point &other);

		/* Destructor */
		~Point();

		/* Getters for x and y */
		Fixed getX() const;
		Fixed getY() const;
	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif