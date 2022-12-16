#include "whatever.hpp"

template <typename T>
Whatever<T>::Whatever()
{
}

template <typename T>
Whatever<T>::Whatever(Whatever const& w)
{
}

template <typename T>
Whatever<T>::~Whatever()
{
}

template <typename T>
Whatever<T>& Whatever<T>::operator=(Whatever<T> const& w)
{
}


template <typename T>
void	Whatever<T>::swap(T& a, T& b)
{
	T& temp = a;

	a = b;
	b = temp;
}

template <typename T>
T const&	Whatever<T>::min(T const& a, T const& b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T const&	Whatever<T>::max(T const& a, T const& b)
{
	if (a > b)
		return a;
	else
		return b;
}