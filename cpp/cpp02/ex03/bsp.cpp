#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	/*-------------------------------------
	PA x PC, PC x PB, PB x PA
	(Xa - Xp)(Yc - Yp) - (Xc - Xp)(Ya - Yp)
	(Xc - Xp)(Yb - Yp) - (Xb - Xp)(Yc - Yp)
	(Xb - Xp)(Ya - Yp) - (Xa - Xp)(Yb - Yp)
	---------------------------------------*/
	
	int check1 = (a.getx() - point.getx()) * (c.gety() - point.gety()) \
				  - (c.getx() - point.getx()) * (a.gety() - point.gety());
	int check2 = (c.getx() - point.getx()) * (b.gety() - point.gety()) \
				  - (b.getx() - point.getx()) * (c.gety() - point.gety());
	int check3 = (b.getx() - point.getx()) * (a.gety() - point.gety()) \
				  - (a.getx() - point.getx()) * (b.gety() - point.gety());

	if ((check1 > 0 && check2 > 0 && check3 > 0)
		|| (check1 < 0 && check2 < 0 && check3 < 0))
		return true;
	else
		return false;
}