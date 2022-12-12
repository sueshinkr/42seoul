#include "Point.hpp"

void	print_triangle(Point const a, Point const b, Point const c, Point const point)
{
	for (int y = 50; y >= 0; y--)
	{
		for (int x = 0; x <= 50; x++)
		{
			if ((x == roundf(a.getx()) && y == roundf(a.gety()))
				|| (x == roundf(b.getx()) && y == roundf(b.gety()))
				|| (x == roundf(c.getx()) && y == roundf(c.gety())))
				std::cout << "*";
			else if (x == roundf(point.getx()) && y == roundf(point.gety()))
				std::cout << "@";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

float	randomfloat(void)
{
	int low = 0;
	int high = 50;

	return (low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX);
}


int	main( void ) {

	srand(time(NULL));

	bool is_success = false;
	while (!is_success)
	{
		Point a(randomfloat(), randomfloat());
		Point b(randomfloat(), randomfloat());
		Point c(randomfloat(), randomfloat());
		Point target(randomfloat(), randomfloat());

		if (bsp(a, b, c, target))
		{
			std::cout << "point a : (" << a.getx() << ", " << a.gety() << ")\n";
			std::cout << "point b : (" << b.getx() << ", " << b.gety() << ")\n";
			std::cout << "point c : (" << c.getx() << ", " << c.gety() << ")\n";
			std::cout << "point target : (" << target.getx() << ", " << target.gety() << ")\n";
			std::cout << "target is in the triangle\n";

			print_triangle(a, b, c, target);
			is_success = true;
		}
	}

	return 0;
}