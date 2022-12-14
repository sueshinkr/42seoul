#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& sh);

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& sh);
		~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const& br) const;
};