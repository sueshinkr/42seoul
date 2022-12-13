#include <iostream>

class TooHigh
{
	public:
		void	err_msg();
};

class TooLow
{
	public:
		void	err_msg();
};


class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
		TooHigh				GradeTooHighException;
		TooLow				GradeTooLowException;

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);

		std::string	getName() const;
		int			getGrade() const;
		void		inc_Grade();
		void		dec_Grade();
	
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br);