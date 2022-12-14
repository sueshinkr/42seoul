#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const& in)
{
	(void)in;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(Intern const& in)
{
	(void)in;
	return *this;
}

AForm* Intern::shrubbery_clone(std::string target)
{
	std::cout << "Intern creates ShrubberyCreationForm\n";
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::robotomy_clone(std::string target)
{
	std::cout << "Intern creates RobotomyRequestForm\n";
	return (new RobotomyRequestForm(target));
}

AForm* Intern::presidential_clone(std::string target)
{
	std::cout << "Intern creates PresidentialPardonForm\n";
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string form_type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*fcnPtr[3])(std::string) = {&Intern::shrubbery_clone, &Intern::robotomy_clone, &Intern::presidential_clone};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (form_type[i] == name)
			{
				return ((this->*fcnPtr[i])(target));
			}
		}
		throw Intern::NotExistFormException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern can\'t work because " << e.what() << '\n';
		return NULL;
	}
}

char const* Intern::NotExistFormException::what() const throw()
{
	return "Form doesn't exist";
}