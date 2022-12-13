#include "Bureaucrat.hpp"

void	TooHigh::err_msg()
{
	std::cerr << "TooHigh\n";
}

void	TooLow::err_msg()
{
	std::cerr << "TooHigh\n";
}



Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	throw Bureaucrat::GradeTooHighException;
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{

}

Bureaucrat::Bureaucrat(int grade) : name("default"), grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException;
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int			Bureaucrat::getGrade() const
{
	return grade;
}

void		Bureaucrat::inc_Grade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException;
	grade--;
}

void		Bureaucrat::dec_Grade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException;
	grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br)
{
	os << br.getName() << ", bureaucrat grade " << br.getGrade();

	return os;
}