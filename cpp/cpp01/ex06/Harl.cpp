#include "Harl.hpp"

Harl::Harl()
{
	level_list[0] = "DEBUG";
	level_list[1] = "INFO";
	level_list[2] = "WARNING";
	level_list[3] = "ERROR";
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
			  << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
			  << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
			  << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n"
			  << "I've been coming for years whereas you started working here since last month.\n"
			  << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n"
			  << std::endl;
}

void	Harl::complain(int i)
{	
	switch(i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
	}
}