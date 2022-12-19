#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "class Cat constructed\n";
}

Cat::Cat(Cat const& cat) : Animal(cat)
{
	std::cout << "class Cat is constructed by copy\n";
}

Cat::~Cat()
{
	std::cout << "class Cat is destructed\n";
}

Cat&	Cat::operator=(Cat const& cat)
{
	if (this != &cat)
	{
		setType(cat.getType());
	}
	std::cout << "class Cat is copied by assignment\n";

	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "Meowwwww!\n";
}