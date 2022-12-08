#include "Weapon.hpp"

Weapon::Weapon()
{
	type = nullptr;
}

Weapon::Weapon(std::string type_name)
{
	type = type_name;
}

const std::string&	Weapon::getType(void)
{
	return type;
}

void				Weapon::setType(std::string newtype)
{
	type = newtype;
}