#include "Zombie.hpp"

Zombie::Zombie(std::string newname)
{
	name = newname;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " is dead\n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}