#include <iostream>

template <typename T>
void	iter(T* arr, size_t len, void (*fn)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		fn(arr[i]);
	}
}

template <typename T>
void	print(T& a)
{
	std::cout << a << " : ";
}