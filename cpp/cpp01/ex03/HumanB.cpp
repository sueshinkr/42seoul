#include "HumanB.hpp"

HumanB::HumanB(std::string newname) : name(newname), wp(NULL)
{
}

void	HumanB::attack()
{
	if (!wp)
		std::cout << name << " has no weapon\n";
	else
		std::cout << name << " attacks with their " << wp->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& newwp)
{
	wp = &newwp;
}