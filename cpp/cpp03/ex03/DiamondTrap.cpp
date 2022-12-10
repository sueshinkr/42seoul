#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
	name = "default";
	Hit_points = FragTrap::Hit_points;
	Energy_points = ScavTrap::Energy_points;
	Attack_damage = FragTrap::Attack_damage;

	std::cout << "DiamondTrap " << name << " is made\n";
}

DiamondTrap::DiamondTrap(std::string newname) : ClapTrap(newname + "_clap_name")
{
	name = newname;
	Hit_points = FragTrap::Hit_points;
	Energy_points = ScavTrap::Energy_points;
	Attack_damage = FragTrap::Attack_damage;

	std::cout << "DiamondTrap " << name << " is made\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt)
{
	name = dt.name;
	std::cout << "DiamondTrap " << name << " is made by copy\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is destructed\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& dt)
{
	ClapTrap::name = dt.ClapTrap::name;
	name = dt.name;
	Hit_points = dt.Hit_points;
	Energy_points = dt.Energy_points;
	Attack_damage = dt.Attack_damage;

	std::cout << "DiamondTrap " << name << " is copied\n";

	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap : " << name << ", ClapTrap : " << ClapTrap::name << std::endl;
}
