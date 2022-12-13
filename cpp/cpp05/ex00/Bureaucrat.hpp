#include <iostream>

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);

		std::string	getName() const;
		int			getGrade() const;
		void		inc_Grade();
		void		dec_Grade();

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};
	
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br);
