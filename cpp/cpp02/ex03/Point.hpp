#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float f1, const float f2);
		Point(const Point& pt);
		Point&	operator=(const Point& pt);
		~Point();

		float	getx(void) const;
		float	gety(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);