#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	DogBrain = new Brain;
	std::cout << "class Dog constructed\n";
}

Dog::Dog(Dog const& dog) : Animal(dog)
{
	DogBrain = new Brain(*(dog.DogBrain));
	std::cout << "class Dog is constructed by copy\n";
}

Dog::~Dog()
{
	delete DogBrain;
	std::cout << "class Dog is destructed\n";
}

Dog&	Dog::operator=(Dog const& dog)
{
	if (this != &dog)
	{
		setType(dog.getType());

		if (DogBrain)
			delete DogBrain;
		DogBrain = new Brain(*(dog.DogBrain));
	}

	std::cout << "class Dog is copied by assignment\n";

	return *this;
}

void		Dog::makeSound() const
{
	std::cout << "Bow-Wow!\n";
}

Brain*		Dog::getBrain() const
{
	return DogBrain;
}

