#pragma once
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	name;
		bool				sign;
		int const			grade_to_sign;
		int const			grade_to_execute;
		Form&	operator=(Form const& fm);

	public:
		Form();
		Form(std::string name, int gtos, int gtoe);
		Form(Form const& fm);
		~Form();

		std::string	getName() const;
		bool		getSign() const;
		int			getGrade_to_sign() const;
		int			getGrade_to_execute() const;
		void		beSigned(Bureaucrat const& br);
};

std::ostream&	operator<<(std::ostream& os, const Form& fm);
