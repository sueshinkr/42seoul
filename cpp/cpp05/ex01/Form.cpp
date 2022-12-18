#include "Form.hpp"

Form::Form() : name("default"), sign(false), grade_to_sign(1), grade_to_execute(1)
{
}

Form::Form(std::string name, int gtos, int gtoe)
	: name(name), sign(false), grade_to_sign(gtos), grade_to_execute(gtoe)
{
}

Form::Form(Form const& fm)
	: name(fm.getName()), sign(fm.getSign()),
	  grade_to_sign(fm.getGrade_to_sign()), grade_to_execute(fm.getGrade_to_execute())
{
}

Form::~Form()
{
}

Form&	Form::operator=(Form const& fm)
{
	if (this != &fm)
	{
		*(const_cast<std::string*>(&name)) = fm.getName();
		sign = fm.getSign();
		*(const_cast<int*>(&grade_to_sign)) = fm.getGrade_to_sign();
		*(const_cast<int*>(&grade_to_execute)) = fm.getGrade_to_execute();
	}

	return *this;
}

std::string	Form::getName() const
{
	return name;
}

bool		Form::getSign() const
{
	return sign;
}

int			Form::getGrade_to_sign() const
{
	return grade_to_sign;
}

int			Form::getGrade_to_execute() const
{
	return grade_to_execute;
}

void		Form::beSigned(Bureaucrat const& br)
{
	if (br.getGrade() <= getGrade_to_sign())
		sign = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const Form& fm)
{
	os << fm.getName() << ", Form signed : " << std::boolalpha << fm.getSign()
	   << ", required grade to sign : " << fm.getGrade_to_sign()
	   << ", required grade to excute : " << fm.getGrade_to_execute();

	return os;
}

char const*	Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

char const*	Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}
