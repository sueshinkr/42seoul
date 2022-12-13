#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat br;
		std::cout << br << std::endl;

		Bureaucrat br1(150);
		std::cout << br1 << std::endl;

		Bureaucrat br2("br2", 10);
		std::cout << br2 << std::endl;

		Bureaucrat br3("br3", 200);
		std::cout << br3 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat br4("br4", 1);
		Bureaucrat br5("br5", 150);
		std::cout << br4 << std::endl;
		std::cout << br5 << std::endl;

		br4.dec_Grade();
		br5.inc_Grade();
		std::cout << br4 << std::endl;
		std::cout << br5 << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
