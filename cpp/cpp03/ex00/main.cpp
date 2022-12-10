#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("a");
	ClapTrap b("b");

	for (int i = 0; i < 10; i++)
	{
		a.attack("b");
		b.takeDamage(1);
	}
	a.attack("b");
	a.beRepaired(1);
	b.attack("a");
	b.beRepaired(10);

	std::cout << "===========================\n";

	ClapTrap c;
	c = a;
	ClapTrap d(b);

	c.attack("d");
	c.beRepaired(1);
	d.attack("c");
	d.beRepaired(1);

	std::cout << "===========================\n";

	ClapTrap e("e");
	e.beRepaired(10);
}