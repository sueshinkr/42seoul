#include "Array.hpp"

int	main()
{
	try
	{
		Array<int> i_arr1(5);
		for (int i = 0; i < 5; i++)
		{
			i_arr1[i] = i;
			std::cout << "i_arr[" << i << "] : " << i_arr1[i] << std::endl;
		}

		Array<int> i_arr2(i_arr1);
		for (int i = 0; i < 5; i++)
			std::cout << "i_arr2[" << i << "] : " << i_arr2[i] << std::endl;

		Array<int> i_arr3;
		i_arr3 = i_arr2;
		for (int i = 0; i <= 5; i++)
			std::cout << "i_arr3[" << i << "] : " << i_arr3[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}