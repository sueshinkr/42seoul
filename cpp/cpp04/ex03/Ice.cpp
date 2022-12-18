#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const& i) : AMateria(i.getType())
{
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(Ice const& i)
{
	type = i.getType();

	return *this;
}

Ice*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}