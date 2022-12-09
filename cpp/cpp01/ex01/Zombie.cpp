#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string newname)
{
	name = newname;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " is dead\n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string newname)
{
	name = newname;
}