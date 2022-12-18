#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main()
{
	std::vector<int> arr;
	for (int i = 0; i < 10; i++)
		arr.push_back(i);

	try
	{
		while (1)
		{
			int num;
			std::cout << "write the number to find : ";
			std::cin >> num;

			std::vector<int>::iterator iter = easyfind(arr, num);
			std::cout << num << " is number " << *iter + 1 << " argument in this container\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}