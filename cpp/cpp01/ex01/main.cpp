#include "Zombie.hpp"

int	main()
{
	int N = 5;

	Zombie* zb = zombieHorde(N, "hellozombie");

	for (int i = 0; i < N; i++)
	{
		std::cout << "number " << i + 1 << " zombie is born\n";
		zb[i].announce();
	}

	delete [] zb;
	return 0;
}