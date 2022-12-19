#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: name("default"), Hit_points(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << name << " is made\n";
}

ClapTrap::ClapTrap(std::string newname) 
	: name(newname), Hit_points(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << name << " is made\n";
} 

ClapTrap::ClapTrap(const ClapTrap& ct)
	: name(ct.name), Hit_points(ct.Hit_points), Energy_points(ct.Energy_points), Attack_damage(ct.Attack_damage)
{
	std::cout << "ClapTrap " << name << " is made by copy\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destructed\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct)
{
	if (this != &ct)
	{
		name = ct.name;
		Hit_points = ct.Hit_points;
		Energy_points = ct.Energy_points;
		Attack_damage = ct.Attack_damage;
	}

	std::cout << "ClapTrap " << name << " is copied\n";

	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (Hit_points <= 0)
		std::cout << "ClapTrap " << name << " can't attack. it was broken\n";
	else if (Energy_points <= 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack\n";
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		 	      << Attack_damage << " points of damage!\n";
		Energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_points < 0)
		std::cout << "ClapTrap " << name << " can't taken damage. it was broken\n";
	else
	{
		Hit_points -= amount;
		std::cout << "ClapTrap " << name << " has taken " << amount << " damage\n"
				<< "ClapTrap " << name << " has " << Hit_points << " Hit points\n";
		if (Hit_points <= 0)
			std::cout << "ClapTrap " << name << " is broken\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points <= 0)
		std::cout << "ClapTrap " << name << " can't be repaired. it was broken\n";
	else if (Energy_points <= 0)
		std::cout << "ClapTrap " << name << " doesn't have enough energy to be repaired\n";
	else
	{
		Hit_points += amount;
		std::cout << "ClapTrap " << name << " is repaired " << amount << " Hit points\n"
				  << "CalpTrap " << name << " has " << Hit_points << " Hit points\n";
		Energy_points--;
	}
}
