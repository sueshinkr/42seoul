#pragma once
#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const	name;
		bool				sign;
		int const			grade_to_sign;
		int const			grade_to_execute;
		AForm&	operator=(AForm const& fm);

	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, int gtos, int gtoe);
		AForm(AForm const& fm);
		virtual	~AForm();
		

		std::string		getName() const;
		bool			getSign() const;
		int				getGrade_to_sign() const;
		int				getGrade_to_execute() const;
		void			beSigned(Bureaucrat const& br);
		void			check_execute(Bureaucrat const& br) const;
		virtual void	execute(Bureaucrat const& executor) const = 0;
	
	public:
		class NotSignedException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& fm);
