#include "ScavTrap.hpp"

int	main()
{
	ScavTrap a("a");
	ScavTrap b("b");

	a.attack("b");
	b.takeDamage(20);
	
	std::cout << "===========================\n";

	a.attack("b");
	b.takeDamage(20);
	b.beRepaired(10);
	
	std::cout << "===========================\n";

	b.attack("a");
	a.takeDamage(20);
	a.beRepaired(10);

	std::cout << "===========================\n";

	ScavTrap c;
	c = a;
	ScavTrap d(b);

	c.attack("d");
	d.takeDamage(20);

	std::cout << "===========================\n";

	d.attack("c");
	c.takeDamage(20);
	c.beRepaired(30);

	std::cout << "===========================\n";

	ScavTrap e("e");
	e.GuardGate();
}