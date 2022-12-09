#include <iostream>
#include <cstring>

int	main(int argc, char** argv)
{
	char	ch;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
				std::cout << (ch = std::toupper(argv[i][j]));
		}
		std::cout << std::endl;
	}
}
