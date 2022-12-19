#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "class Dog constructed\n";
}

Dog::Dog(Dog const& dog) : Animal(dog)
{
	std::cout << "class Dog is constructed by copy\n";
}

Dog::~Dog()
{
	std::cout << "class Dog is destructed\n";
}

Dog&	Dog::operator=(Dog const& dog)
{
	if (this != &dog)
	{
		setType(dog.getType());
	}
	std::cout << "class Dog is copied by assignment\n";

	return *this;
}

void		Dog::makeSound() const
{
	std::cout << "Bow-Wow!\n";
}

