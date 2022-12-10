#include <iostream>

class ClapTrap
{
	protected:
		std::string	name;
		int			Hit_points;
		int			Energy_points;
		int			Attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string newname);
		ClapTrap(const ClapTrap& ct);
		ClapTrap& operator=(const ClapTrap& ct);
		virtual ~ClapTrap();

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};