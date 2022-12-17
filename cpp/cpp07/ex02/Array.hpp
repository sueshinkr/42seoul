#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		size_t	arr_size;
		T*		arr;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const& arr);
		~Array();
		Array&	operator=(Array const& arr);

		size_t size() const { return arr_size; };
		T& operator[](size_t idx);
		T const& operator[](size_t idx) const;

	public:
		class OutOfBoundException : public std::exception
		{
			public:
				virtual char const*	what() const throw() { return "Ouf of Bounds"; }
		};
};

template <typename T>
Array<T>::Array() : arr_size(0), arr(nullptr)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : arr_size(n)
{
	if (n > 0)
		arr = new T[arr_size];
	else
		arr = nullptr;
}

template <typename T>
Array<T>::Array(Array const& data) : arr_size(data.arr_size)
{
	if (data.arr)
	{
		arr = new T[arr_size];
		for (size_t i = 0; i < arr_size; i++)
			arr[i] = data.arr[i];
	}
	else
		arr = nullptr;
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const& data)
{
	if (this != &data)
	{
		arr_size = data.arr_size;
		delete [] arr;

		if (data.arr)
		{
			arr = new T[arr_size];
			for (size_t i = 0; i < arr_size; i++)
				arr[i] = data.arr[i];
		}
		else
			arr = nullptr;
	}

	return *this;
}

template <typename T>
T&			Array<T>::operator[](size_t idx)
{
	if (idx >= arr_size)
		throw Array::OutOfBoundException();
	else
		return arr[idx];
}

template <typename T>
T const&	Array<T>::operator[](size_t idx) const
{
	if (idx >= arr_size)
		throw Array::OutOfBoundException();
	else
		return arr[idx];
}