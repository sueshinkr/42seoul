#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "class Animal is constructed\n";
}

Animal::Animal(std::string newtype) : type(newtype)
{
	std::cout << "class Animal is constructed\n";
}

Animal::Animal(Animal const& am) : type(am.getType())
{
	std::cout << "class Animal is constructed by copy\n";
}

Animal::~Animal()
{
	std::cout << "class Animal is destructed\n";
}

Animal&	Animal::operator=(Animal const& am)
{
	if (this != &am)
	{
		setType(am.getType());
	}
	std::cout << "class Animal is copied by assignment\n";

	return *this;
}

void		Animal::makeSound() const
{
	std::cout << "What is the Animal's Sound...?\n";
}

std::string	Animal::getType() const
{
	return type;
}

void		Animal::setType(std::string const newtype)
{
	type = newtype;
}

Brain*		Animal::getBrain() const
{
	std::cout << "class Animal doesn't have Brain...";
	return NULL;
}