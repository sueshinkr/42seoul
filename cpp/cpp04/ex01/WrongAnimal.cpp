#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "class WrongAnimal is constructed\n";
}

WrongAnimal::WrongAnimal(std::string newtype) : type(newtype)
{
	std::cout << "class WrongAnimal is constructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& am) : type(am.getType())
{
	std::cout << "class WrongAnimal is constructed by copy\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "class WrongAnimal is destructed\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& am)
{
	setType(am.getType());
	std::cout << "class WrongAnimal is copied by assignment\n";

	return *this;
}

void		WrongAnimal::makeSound() const
{
	std::cout << "!@#$@!%@#%!@#!#%\n";
}

std::string	WrongAnimal::getType() const
{
	return type;
}

void		WrongAnimal::setType(std::string const newtype)
{
	type = newtype;
}

