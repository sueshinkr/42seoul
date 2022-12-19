#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	CatBrain = new Brain;
	std::cout << "class Cat constructed\n";
}

Cat::Cat(Cat const& cat) : Animal(cat)
{
	CatBrain = new Brain(*(cat.CatBrain));
	std::cout << "class Cat is constructed by copy\n";
}

Cat::~Cat()
{
	delete CatBrain;
	std::cout << "class Cat is destructed\n";
}

Cat&	Cat::operator=(Cat const& cat)
{
	if (this != &cat)
	{
		setType(cat.getType());

		if (CatBrain)
			delete CatBrain;
		CatBrain = new Brain(*(cat.CatBrain));
	}

	std::cout << "class Cat is copied by assignment\n";

	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "Meowwwww!\n";
}

Brain*		Cat::getBrain() const
{
	return CatBrain;
}
