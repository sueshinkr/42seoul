#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const& type) : type(type)
{
}

AMateria::AMateria(const AMateria& am) : type(am.getType())
{

}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& am)
{
	type = am.getType();

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