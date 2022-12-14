#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm& operator=(PresidentialPardonForm const& ps);

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const& ps);
		~PresidentialPardonForm();

		virtual void	execute(Bureaucrat const& br) const;
};