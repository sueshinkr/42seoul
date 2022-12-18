#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T& first, int second)
{
	typename T::iterator t_iter;

	t_iter = std::find(first.begin(), first.end(), second);
	
	if (t_iter == first.end())
		throw std::out_of_range("Out of Range");

	return t_iter;
}