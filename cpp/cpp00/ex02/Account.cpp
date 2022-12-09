#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex++ << ";"
			  << "amount:" << checkAmount() << ";" << "created\n";

	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";" << "closed\n";
}

int		Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int		Account::getTotalAmount(void)
{
	return _totalAmount;
}

int		Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";";

	_nbDeposits++;
	_amount += deposit;

	std::cout << "deposits:" << deposit << ";"
			  << "amount:" << checkAmount() << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";"
			  << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused\n";
		return 0;
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << withdrawal << ";"
				  << "amount:" << checkAmount() << ";"
				  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return 1;
	}
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "deposits" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	std::cout << "[" << t->tm_year + 1900 << std::setw(2) << std::setfill('0') << t->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << t->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << t->tm_hour
			  << std::setw(2) << std::setfill('0') << t->tm_min
			  << std::setw(2) << std::setfill('0') << t->tm_sec << "] ";
}

