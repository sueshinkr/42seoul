#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(int grade) : name("default"), grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& br) : name(br.getName()), grade(br.getGrade())
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& br)
{
	static_cast<void>(br);
	return *this;
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
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void		Bureaucrat::dec_Grade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void		Bureaucrat::signForm(AForm& fm)
{
	try
	{
		fm.beSigned(*this);
		std::cout << getName() << " signed " << fm.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << getName() << " couldn't sign " << fm.getName()
				  << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const& fm)
{
	try
	{
		fm.execute(*this);
	}
	catch(std::exception& e)
	{
		std::cerr << getName() << " couldn't execute " << fm.getName()
				  << " because " << e.what() << std::endl;
	}

}

char const*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

char const*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& br)
{
	os << br.getName() << ", bureaucrat grade " << br.getGrade();

	return os;
}



