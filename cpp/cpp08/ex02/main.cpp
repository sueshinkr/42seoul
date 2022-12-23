#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	
	std::cout << "=====================================\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "================================\n";

	std::stack<int> s(mstack);

	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "================================\n";
	std::cout << "================================\n";

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();

	std::cout << list.size() << std::endl;

	std::cout << "================================\n";

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it_list = list.begin();
	std::list<int>::iterator ite_list = list.end();

	++it_list;
	--it_list;

	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}

	std::cout << "================================\n";
	
	std::list<int> s_list(list);

	for (std::list<int>::iterator it = s_list.begin(); it != s_list.end(); it++)
		std::cout << *it << std::endl;

}