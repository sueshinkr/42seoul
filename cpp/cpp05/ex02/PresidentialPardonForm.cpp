#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Robotomy", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& ps) : AForm(ps)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& ps)
{
	static_cast<void>(ps);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const& br) const
{
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox\n";
}