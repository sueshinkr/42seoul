#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	//const Animal*	animal = new Animal();

	delete j;
	delete i;

	std::cout << "===============================\n";

	const Animal*	group[100];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			group[i] = new Dog();
		else
			group[i] = new Cat();
	}

	std::cout << "===============================\n";
	std::cout << group[6]->getType() << " : ";
	group[6]->makeSound();
	std::cout << group[6]->getType() << "\'s Idea is " << group[6]->getBrain()->getIdea(6) << std::endl;
	group[6]->getBrain()->setIdea("I'm dog", 6);
	std::cout << "After setup new Idea, " << group[6]->getType() << "\'s Idea is " << group[6]->getBrain()->getIdea(6) << std::endl;

	std::cout << "===============================\n";
	std::cout << group[5]->getType() << " : ";
	group[5]->makeSound();
	std::cout << group[5]->getType() << "\'s Idea is " << group[5]->getBrain()->getIdea(5) << std::endl;
	group[5]->getBrain()->setIdea("I'm cat", 5);
	std::cout << "After setup new Idea, " << group[5]->getType() << "\'s Idea is " << group[5]->getBrain()->getIdea(5) << std::endl;

	std::cout << "===============================\n";
	Cat* cat1 = new Cat;
	Cat* cat2 = new Cat;
	cat1->getBrain()->setIdea("111111111", 0);

	*cat2 = *cat1;
	std::cout << cat1->getType() << "\'s Idea is " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << cat1->getType() << "\'s Idea is " << cat2->getBrain()->getIdea(0) << std::endl;
	
	cat2->getBrain()->setIdea("222222222", 0);
	std::cout << cat1->getType() << "\'s Idea is " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << cat1->getType() << "\'s Idea is " << cat2->getBrain()->getIdea(0) << std::endl;

	delete cat1;
	delete cat2;

	std::cout << "===============================\n";
	for (int i = 0; i < 10; i++)
		delete group[i];

	return 0;
}
