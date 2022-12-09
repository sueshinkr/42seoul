#include "HumanA.hpp"

HumanA::HumanA(std::string newname, Weapon& newwp) : name(newname), wp(newwp)
{
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << wp.getType() << std::endl;
}