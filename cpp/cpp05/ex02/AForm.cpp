#include "AForm.hpp"

AForm::AForm() : name("default"), sign(false), grade_to_sign(1), grade_to_execute(1)
{
}

AForm::AForm(std::string name) : name(name), sign(false), grade_to_sign(1), grade_to_execute(1)
{
}

AForm::AForm(std::string name, int gtos, int gtoe)
	: name(name), sign(false), grade_to_sign(gtos), grade_to_execute(gtoe)
{
	if (gtos > 150 || gtoe > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (gtos < 1 || gtoe < 1)
		throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(AForm const& fm)
	: name(fm.getName()), sign(fm.getSign()),
	  grade_to_sign(fm.getGrade_to_sign()), grade_to_execute(fm.getGrade_to_execute())
{
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(AForm const& fm)
{
	static_cast<void>(fm);
	return *this;
}

std::string	AForm::getName() const
{
	return name;
}

bool		AForm::getSign() const
{
	return sign;
}

int			AForm::getGrade_to_sign() const
{
	return grade_to_sign;
}

int			AForm::getGrade_to_execute() const
{
	return grade_to_execute;
}

void		AForm::beSigned(Bureaucrat const& br)
{
	if (br.getGrade() <= getGrade_to_sign())
		sign = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

void		AForm::check_execute(Bureaucrat const& br) const
{
	if (getSign() == false)
		throw AForm::NotSignedException();
	else if (br.getGrade() > getGrade_to_execute())
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << br.getName() << " has enough grade to execute\n";		
}

std::ostream&	operator<<(std::ostream& os, const AForm& fm)
{
	os << fm.getName() << ", AForm signed : " << fm.getSign()
	   << ", required grade to sign : " << fm.getGrade_to_sign()
	   << ", required grade to excute : " << fm.getGrade_to_execute();

	return os;
}

char const*	AForm::NotSignedException::what() const throw()
{
	return "Not Signed";
}
