#include <iostream>

int	main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "memory address of the string		: " << &brain << std::endl;
	std::cout << "memory address held by stringPTR	: " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF	: " << &stringREF << std::endl;

	std::cout << "value of the string		: " << brain << std::endl;
	std::cout << "value pointed by stringPTR	: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF	: " << stringREF << std::endl;
}