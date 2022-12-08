#include "Harl.hpp"

int	main(int argc, char** argv)
{
	Harl	h;
	
	if (argc != 2)
	{
		std::cout << "Wrong Argument : Argument must be [level](DEBUG/INFO/WARNING/ERROR)\n";
		return 1;
	}

	std::string level = argv[1];
	for (int i = 0; i < 4; i++)
	{
		if (level == h.level_list[i])
		{
			h.complain(i);
			return 0;
		}
	}
	std::cout << "[ Probably complaining about insignificant problem ]\n";
	return 1;
}