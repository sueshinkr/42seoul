#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), type("Dog")
{
	std::cout << "class Dog constructed\n";
}

Dog::Dog(const Dog& dog) : Animal(dog), type(dog.type)
{
	std::cout << "class Dog is constructed by copy\n";
}

Dog::~Dog()
{
	std::cout << "class Dog is destructed\n";
}

Dog&	Dog::operator=(const Dog& dog)
{
	setType(dog.getType());
	Animal::setType(dog.Animal::getType());
	std::cout << "class Dog is copied by assignment\n";

	return *this;
}

void		Dog::makeSound() const
{
	std::cout << "Bow-Wow!\n";
}

std::string	Dog::getType() const
{
	return type;
}

void		Dog::setType(std::string const newtype)
{
	type = newtype;
}

