#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
