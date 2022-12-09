#include "Zombie.hpp"
#include "iostream"

int	main()
{
	Zombie* first = newZombie("first");
	first->announce();
	randomChump("second");
	delete first;

	return 0;
}