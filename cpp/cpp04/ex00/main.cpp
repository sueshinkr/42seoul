#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*		meta = new Animal();
	const Animal*		j = new Dog();
	const Animal*		i = new Cat();
	const WrongAnimal*	wrong = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	delete j;
	delete i;
	delete meta;
	delete wrong;

	return 0;
}
