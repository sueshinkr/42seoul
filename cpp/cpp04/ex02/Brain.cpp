#include "Brain.hpp"
#include <string>

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "default idea";

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

Brain&		Brain::operator=(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];

	std::cout << "class Brain is copied by assignment\n";

	return *this;
}

std::string	Brain::getIdea(int idx)
{
	return ideas[idx];
}

void		Brain::setIdea(std::string idea, int idx)
{
	ideas[idx] = idea;
}