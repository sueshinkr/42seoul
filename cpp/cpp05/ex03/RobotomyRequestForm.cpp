#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rb) : AForm(rb)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rb)
{
	static_cast<void>(rb);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const& br) const
{
	check_execute(br);
	std::cout << "Sorry, I'll make some noses...\n"
			  << "Drrrrrrrrrrrrrrrrrrrrrrr\n";

	srand(time(NULL));
	if (rand() % 2 == 1)
		std::cout << getName() << " has been robotomized successfully!\n";
	else
		std::cout << "Umm... Sry; " << getName() << "\'s robotomization failed...\n";
}