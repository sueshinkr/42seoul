#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;
	std::string	cmd;

	while (1)
	{
		std::cout << "==============================\n";
		std::cout << "Select CMD (ADD, SEARCH, EXIT)\n";
		std::getline(std::cin, cmd);
		if (std::cin.eof() || std::cin.bad())
		{
			std::cout << "BAD INPUT. EXIT PROGRAM\n";
			exit(1);
		}
		if (cmd == "ADD")
			pb.add_contact();
		else if (cmd == "SEARCH")
			pb.search_contact();
		else if (cmd == "EXIT")
		{
			std::cout << "EXIT PROGRAM\n";
			break;
		}
		else
			std::cout << "Please input the right CMD (ADD, SEARCH, EXIT)\n";
	}
}