#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& sh) : AForm(sh)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& sh)
{
	static_cast<void>(sh);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& br) const
{
	check_execute(br);
	std::string file = getName() + "_shrubbery";
	std::ofstream fout(file);
	fout <<
	"		  		*			\n\
			   ***			\n\
			  *****			\n\
			*********		\n\
			 *******		\n\
		  *************		\n\
		   ***********		\n\
		*****************	\n\
			   @@@			\n\
			   @@@			\n";
	std::cout << "ASCII Tree is made to " << file << std::endl;
}