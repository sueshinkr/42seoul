#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

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

	return 0;
}
