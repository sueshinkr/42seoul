#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;

	std::cout << "FragTrap " << name << " is made\n";
}

FragTrap::FragTrap(std::string newname) : ClapTrap(newname)
{
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;

	std::cout << "FragTrap " << name << " is made\n";
}

FragTrap::FragTrap(const FragTrap& ft) : ClapTrap(ft)
{
	std::cout << "FragTrap " << name << " is made by copy\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destructed\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& ft)
{
	if (this != &ft)
	{
		name = ft.name;
		Hit_points = ft.Hit_points;
		Energy_points = ft.Energy_points;
		Attack_damage = ft.Attack_damage;
	}

	std::cout << "FragTrap " << name << " is copied\n";

	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests high fives!\n";
}
