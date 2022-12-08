#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		wp;

	public:
		HumanB(std::string newname);
		void	attack();
		void	setWeapon(Weapon& newwp);
};

#endif