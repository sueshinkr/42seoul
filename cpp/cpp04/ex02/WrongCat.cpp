#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"), type("WrongCat")
{
	std::cout << "class WrongCat constructed\n";
}

WrongCat::WrongCat(WrongCat const& cat) : WrongAnimal(cat), type(cat.type)
{
	std::cout << "class WrongCat is constructed by copy\n";
}

WrongCat::~WrongCat()
{
	std::cout << "class WrongCat is destructed\n";
}

WrongCat&	WrongCat::operator=(WrongCat const& cat)
{
	if (this != &cat)
	{
		setType(cat.getType());
		WrongAnimal::setType(cat.WrongAnimal::getType());
	}
	std::cout << "class WrongCat is copied by assignment\n";

	return *this;
}

void		WrongCat::makeSound()
{
	std::cout << "Meowwwww!\n";
}

std::string	WrongCat::getType() const
{
	return type;
}

void		WrongCat::setType(std::string const newtype)
{
	type = newtype;
}

