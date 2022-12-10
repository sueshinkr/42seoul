#include "FragTrap.hpp"

int	main()
{
	FragTrap a("a");
	FragTrap b("b");

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

	FragTrap c;
	c = a;
	FragTrap d(b);

	c.attack("d");
	d.takeDamage(30);

	std::cout << "===========================\n";

	d.attack("c");
	c.takeDamage(30);
	c.beRepaired(30);

	std::cout << "===========================\n";

	FragTrap e("e");
	e.highFivesGuys();
}
