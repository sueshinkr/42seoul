#include "Convert.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please write only one argument\n";
		return 1;
	}

	Convert cv(argv[1]);
	cv.Check();
}
