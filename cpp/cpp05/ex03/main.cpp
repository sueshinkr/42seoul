#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat br1("br1", 44);
		std::cout << br1 << std::endl;
		
		Intern someRandomIntern;
		AForm* rrf;

		if ((rrf = someRandomIntern.makeForm("robotomy request", "aaaaaa")))
		{
			br1.executeForm(*rrf);
			br1.signForm(*rrf);
			br1.executeForm(*rrf);
		}

		if ((rrf = someRandomIntern.makeForm("shrubbery creation", "bbbbbb")))
		{
			br1.executeForm(*rrf);
			br1.signForm(*rrf);
			br1.executeForm(*rrf);
		}

		if ((rrf = someRandomIntern.makeForm("presidential pardon", "cccccc")))
		{
			br1.executeForm(*rrf);
			br1.signForm(*rrf);
			br1.executeForm(*rrf);
		}

		if ((rrf = someRandomIntern.makeForm("wowwowowowowow", "cccccc")))
		{
			br1.executeForm(*rrf);
			br1.signForm(*rrf);
			br1.executeForm(*rrf);
		}
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
