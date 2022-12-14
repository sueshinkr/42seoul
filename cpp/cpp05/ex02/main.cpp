#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat br1("br1", 44);
		std::cout << br1 << std::endl;
		
		ShrubberyCreationForm sh1("sh1");
		br1.executeForm(sh1);
		br1.signForm(sh1);
		br1.executeForm(sh1);

		std::cout << "====================\n";
		RobotomyRequestForm rb1("rb1");
		br1.executeForm(rb1);
		br1.signForm(rb1);
		br1.executeForm(rb1);

		std::cout << "====================\n";
		PresidentialPardonForm ps1("ps1");
		br1.executeForm(ps1);
		br1.signForm(ps1);
		br1.executeForm(ps1);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
