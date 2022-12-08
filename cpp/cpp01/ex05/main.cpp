#include "Harl.hpp"
#include <cstdlib>

int	main()
{
	Harl	h;
	int		num;
	srand(0);

	std::cout << "write the number\n";
	std::cin >> num;
	for (int i = 0; i < num; i++)
	{
		int temp = rand() % 4;
		std::cout << i << " : " << h.level_list[temp] << std::endl;
		h.complain(h.level_list[temp]);
	}
}