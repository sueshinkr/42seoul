#include "Brain.hpp"
#include <string>

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea";
	std::cout << "class Brain constructed\n";
}

Brain::Brain(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
	std::cout << "class Brain is constructed by copy\n";
}

Brain::~Brain()
{
	std::cout << "class Brain is destructed\n";
}

Brain&	Brain::operator=(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];

	std::cout << "class Brain is copied by assignment\n";

	return *this;
}
