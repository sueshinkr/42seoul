#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm& operator=(RobotomyRequestForm const& rb);

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& rb);
		~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const& br) const;
};