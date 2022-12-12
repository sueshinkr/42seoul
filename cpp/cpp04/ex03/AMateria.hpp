#pragma once
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& am);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& am);

		std::string const&	getType() const;
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};