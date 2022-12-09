#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	pb;
	std::string	cmd;

	while (1)
	{
		std::cout << "==============================\n";
		std::cout << "Select CMD (ADD, SEARCH, EXIT)\n";
		std::cin >> cmd;
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