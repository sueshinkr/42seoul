#include "Character.hpp"

Character::Character()
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = nullptr;
	}
}

Character::Character(std::string name) : name(name)
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = nullptr;
	}
}

Character::Character(Character& ch) : name(ch.getName())
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = ch.materia[idx];
	}
}

Character::~Character()
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (materia[idx])
		{
			delete materia[idx];
			materia[idx] = nullptr;
		}
	}
}

Character& Character::operator=(Character& ch)
{
	name = ch.getName();
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = ch.materia[idx];
	}
	
	return *this;
}

std::string const&	Character::getName() const
{
	return name;
}

void				Character::equip(AMateria* m)
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (materia[idx] == nullptr)
		{
			materia[idx] = m;
			return ;
		}
	}
	std::cout << name << " is already equipped 4 materia\n";
}

void				Character::unequip(int idx)
{
	if (materia[idx])
		materia[idx] = nullptr;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && materia[idx])
		materia[idx]->use(target);
	else
		std::cout << "materia " << idx << " doesn't exist\n";
}