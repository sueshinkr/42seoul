#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		wp;

	public:
		HumanA(std::string newname, Weapon& newwp);
		void	attack();
};

#endif