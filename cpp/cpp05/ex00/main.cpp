#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat br;
		std::cout << br << std::endl;

		Bureaucrat br1(151);
		std::cout << br1 << std::endl;
	}
	catch(std::exception & e)
	{

	}
	catch(Bureaucrat::)
	{
		std::cerr << e.what() << '\n';
	}
}