#include "HumanB.hpp"

HumanB::HumanB(std::string newname) : name(newname)
{
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << wp->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& newwp)
{
	wp = &newwp;
}