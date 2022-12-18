#pragma once
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(AMateria const& am);
		virtual ~AMateria();
		AMateria& operator=(AMateria const& am);

		std::string const&	getType() const;
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};