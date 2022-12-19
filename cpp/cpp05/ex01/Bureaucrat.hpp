#pragma once
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		std::string	const	name;
		int					grade;
		Bureaucrat& operator=(Bureaucrat const& br);

	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& br);
		~Bureaucrat();
		
		std::string	getName() const;
		int			getGrade() const;
		void		inc_Grade();
		void		dec_Grade();
		void		signForm(Form& fm);

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

std::ostream&	operator<<(std::ostream& os,Bureaucrat const& br);
