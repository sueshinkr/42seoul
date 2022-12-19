#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;

	std::cout << "ScavTrap " << name << " is made\n";
}

ScavTrap::ScavTrap(std::string newname) : ClapTrap(newname)
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;

	std::cout << "ScavTrap " << name << " is made\n";
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st)
{
	std::cout << "ScavTrap " << name << " is made by copy\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destructed\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& st)
{
	if (this != &st)
	{
		name = st.name;
		Hit_points = st.Hit_points;
		Energy_points = st.Energy_points;
		Attack_damage = st.Attack_damage;
	}

	std::cout << "ScavTrap " << name << " is copied\n";

	return *this;
}

void		ScavTrap::attack(const std::string& target)
{
	if (Hit_points <= 0)
		std::cout << "ScavTrap " << name << " can't attack. it was broken\n";
	else if (Energy_points <= 0)
		std::cout << "ScavTrap " << name << " doesn't have enough energy to attack\n";
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
		 	      << Attack_damage << " points of damage!\n";
		Energy_points--;
	}
}

void	ScavTrap::GuardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}
