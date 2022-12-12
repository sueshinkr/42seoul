#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), type("Cat")
{
	CatBrain = new Brain;
	std::cout << "class Cat constructed\n";
}

Cat::Cat(const Cat& cat) : Animal(cat), type(cat.type)
{
	CatBrain = new Brain(*(cat.CatBrain));
	std::cout << "class Cat is constructed by copy\n";
}

Cat::~Cat()
{
	delete CatBrain;
	std::cout << "class Cat is destructed\n";
}

Cat&	Cat::operator=(const Cat& cat)
{
	setType(cat.getType());
	Animal::setType(cat.Animal::getType());

	delete CatBrain;
	CatBrain = new Brain(*(cat.CatBrain));

	std::cout << "class Cat is copied by assignment\n";

	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "Meowwwww!\n";
}

std::string	Cat::getType() const
{
	return type;
}

void		Cat::setType(std::string const newtype)
{
	type = newtype;
}

Brain*		Cat::getBrain() const
{
	return CatBrain;
}
