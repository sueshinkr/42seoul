#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int			Hit_points;
		int			Energy_points;
		int			Attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string newname);
		ClapTrap(const ClapTrap& ct);
		ClapTrap& operator=(const ClapTrap& ct);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};