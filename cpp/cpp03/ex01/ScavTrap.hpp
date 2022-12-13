#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string newname);
		ScavTrap(const ScavTrap& st);
		ScavTrap& operator=(const ScavTrap& st);
		~ScavTrap();

		void	attack(const std::string& target);
		void	GuardGate();
};