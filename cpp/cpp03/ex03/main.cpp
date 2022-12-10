#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap a("a");
	DiamondTrap b("b");

	a.attack("b");
	b.takeDamage(30);
	
	std::cout << "===========================\n";

	a.attack("b");
	b.takeDamage(30);
	b.beRepaired(10);
	
	std::cout << "===========================\n";

	b.attack("a");
	a.takeDamage(30);
	a.beRepaired(10);

	std::cout << "===========================\n";

	DiamondTrap c;
	c = a;
	DiamondTrap d(b);

	c.attack("d");
	d.takeDamage(30);

	std::cout << "===========================\n";

	d.attack("c");
	c.takeDamage(30);
	c.beRepaired(30);

	std::cout << "===========================\n";

	DiamondTrap e("e");
	e.GuardGate();
	e.highFivesGuys();
}
