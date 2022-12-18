#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const& type) : type(type)
{
}

AMateria::AMateria(AMateria const& am) : type(am.getType())
{

}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(AMateria const& am)
{
	if(this != &am)
	{
		type = am.getType();
	}

	return *this;
}

std::string const&	AMateria::getType() const
{
	return type;
}

AMateria*			AMateria::clone() const
{
	return (new AMateria(type));
}

void				AMateria::use(ICharacter& target)
{
	(void)target;
}