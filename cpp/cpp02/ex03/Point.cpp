#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float f1, const float f2) : x(f1), y(f2)
{
}


Point::Point(const Point& pt) : x(pt.x), y(pt.y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point& pt)
{
	(void)pt;
	std::cout << "Can't assign to const member variable\n";

	return *this;
}

float	Point::getx(void) const
{
	return x.toFloat();
}

float	Point::gety(void) const
{
	return y.toFloat();
}



