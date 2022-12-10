#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	
	public:
		DiamondTrap();
		DiamondTrap(std::string newname);
		DiamondTrap(const DiamondTrap& dt);
		DiamondTrap& operator=(const DiamondTrap& dt);
		~DiamondTrap();
	
		void	attack(const std::string& target);
		void	whoAmI();
};
