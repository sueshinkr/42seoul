#include "iter.hpp"

#define ARR_SIZE 5

int	main()
{
	int			i_arr[ARR_SIZE] = {1, 2, 3, 4, 5};
	float		f_arr[ARR_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	str_arr[ARR_SIZE] = {"a", "bb", "ccc", "dddd", "eeeee"};

	iter(i_arr, ARR_SIZE, print);
	std::cout << "\n===========================\n";
	iter(f_arr, ARR_SIZE, print);
	std::cout << "\n===========================\n";
	iter(str_arr, ARR_SIZE, print);
}