#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*		j = new Dog();
	const Animal*		i = new Cat();

	delete j;
	delete i;

	return 0;
}

// getBrain만 넣으면될듯?
