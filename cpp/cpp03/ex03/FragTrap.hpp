#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string newname);
		FragTrap(const FragTrap& st);
		FragTrap& operator=(const FragTrap& st);
		~FragTrap();

		void	highFivesGuys(void);
};
