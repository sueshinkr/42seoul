#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void	add_data();
		bool	is_exist();
		void	show(int idx);
		void	show_secret();
};

class PhoneBook
{
	private:
		Contact	contact[8];
		int		idx;

	public:
		PhoneBook();
		void	add_contact();
		void	search_contact();
		void	show_list();
};
