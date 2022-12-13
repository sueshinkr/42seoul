#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat br1("br1", 5);
		std::cout << br1 << std::endl;
		
		Form fm1("fm1", 10, 10);
		std:: cout << fm1 << std::endl;
		
		br1.signForm(fm1);

		Bureaucrat br2("br2", 100);
		std::cout << br2 << std::endl;
		
		Form fm2("fm2", 10, 10);
		std:: cout << fm2 << std::endl;
		
		br2.signForm(fm2);

	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
