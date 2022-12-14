#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* shrubbery_clone(std::string target);
		AForm* robotomy_clone(std::string target);
		AForm* presidential_clone(std::string target);

	public:
		Intern();
		Intern(Intern const& in);
		~Intern();
		Intern&	operator=(Intern const& in);

		AForm*	makeForm(std::string name, std::string target);

	public:
		class NotExistFormException : public std::exception
		{
			public:
				virtual char const*	what() const throw();
		};

};