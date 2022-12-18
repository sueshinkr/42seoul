#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const& c) : AMateria(c.getType())
{
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(Cure const& c)
{
	type = c.getType();

	return *this;
}

Cure*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}