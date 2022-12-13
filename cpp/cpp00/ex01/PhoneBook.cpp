#include "PhoneBook.hpp"

void	Contact::add_data()
{
	std::cout << "first name : ";
	std::getline(std::cin, first_name);
	while (first_name.find_first_not_of(" \t\v\f\r") == std::string::npos)
	{
		std::cout << "Please write the first name\nfirst name : ";
		std::getline(std::cin, first_name);
	}

	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	while (last_name.find_first_not_of(" \t\v\f\r") == std::string::npos)
	{
		std::cout << "Please write the last name\nlast name : ";
		std::getline(std::cin, last_name);
	}

	std::cout << "nickname : ";
	std::getline(std::cin, nick_name);
	while (nick_name.find_first_not_of(" \t\v\f\r") == std::string::npos)
	{
		std::cout << "Please write the nickname\nnickname : ";
		std::getline(std::cin, nick_name);
	}

	std::cout << "phone number : ";
	std::getline(std::cin, phone_number);
	while (phone_number.find_first_not_of(" \t\v\f\r") == std::string::npos)
	{
		std::cout << "Please write the phone number\nphone number : ";
		std::getline(std::cin, phone_number);
	}

	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret);
	while (darkest_secret.find_first_not_of(" \t\v\f\r") == std::string::npos)
	{
		std::cout << "Please write the darkest secret\ndarkest secret : ";
		std::getline(std::cin, darkest_secret);
	}
}

bool	Contact::is_exist()
{
	if (first_name.empty())
		return 0;
	return 1;
}

void	Contact::show(int idx)
{
	std::cout << std::setfill(' ') << std::setw(10) << idx << "|";

	std::cout << std::setfill(' ') << std::setw(10);
	if (first_name.length() > 10)
		std::cout << (first_name.substr(0, 9) + ".") << "|";
	else
		std::cout << first_name << "|";

	std::cout << std::setfill(' ') << std::setw(10);
	if (last_name.length() > 10)
		std::cout << (last_name.substr(0, 9) + ".") << "|";
	else
		std::cout << last_name << "|";

	std::cout << std::setfill(' ') << std::setw(10);
	if (nick_name.length() > 10)
		std::cout << (nick_name.substr(0, 9) + ".") << "|" << std::endl;
	else
		std::cout << nick_name << "|" << std::endl;
}

void	Contact::show_secret()
{
	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nick_name << std::endl;
	std::cout << "phone number : " << phone_number << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}

void	PhoneBook::add_contact()
{
	if (idx >= 8)
	{
		std::cout << "WARNING : data will be OVERWRITTEN\n";
		contact[idx % 8].add_data();
	}
	else
		contact[idx].add_data(); 
	idx++;
}

void	PhoneBook::show_list()
{
	std::cout << std::left
			  << std::setfill(' ') << std::setw(10) << "index" << "|" 
			  << std::setfill(' ') << std::setw(10) << "firstname" << "|"
			  << std::setfill(' ') << std::setw(10) << "lastname" << "|"
			  << std::setfill(' ') << std::setw(10) << "nickname" << "|" << std::endl
			  << std::right;
}

void	PhoneBook::search_contact()
{
	int	num;

	if (!contact[0].is_exist())
	{
		std::cout << "there is no phone number in this phonebook\n";
		return ;
	}
	show_list();
	for (int i = 0; i < 8 && contact[i].is_exist(); i++)
		contact[i].show(i);
	std::cout << "Select index\n";
	while (!(std::cin >> num) || num < 0 || num >= std::min(idx, 8))
	{
		std::cout << "index must be 0 to " << std::min(idx - 1, 7) << ". Please write the right number" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	contact[num].show_secret();
}

PhoneBook::PhoneBook() : idx(0)
{
}
