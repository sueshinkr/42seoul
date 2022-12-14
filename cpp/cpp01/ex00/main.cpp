#include "Zombie.hpp"

int	main()
{
	Zombie* first = newZombie("first");
	first->announce();
	randomChump("second");
	delete first;

	return 0;
}