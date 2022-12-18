#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria*	materia[4];

	public:
		Character();
		Character(std::string name);
		Character(Character const& ch);
		~Character();
		Character& operator=(Character const& ch);

		virtual std::string const&	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};