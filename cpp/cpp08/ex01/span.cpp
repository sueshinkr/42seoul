#include "span.hpp"

Span::Span() : n(0)
{
}

Span::Span(unsigned int N) : n(N)
{
}

Span::Span(Span const& sp) : n(sp.n), data(sp.data)
{
}

Span::~Span()
{
}

Span&	Span::operator=(Span const& sp)
{
	if (this != &sp)
	{
		n = sp.n;
		data = sp.data;
	}

	return *this;
}

void	Span::addNumber(int num)
{
	if (data.size() == n)
		throw std::out_of_range("data is already full");
	else
		data.push_back(num);
}

int		Span::shortestSpan()
{
	if (data.size() <= 1)
		throw std::logic_error("data doesn't have enough number to find shortest data");
	else
	{
		int min = INT_MAX;
		Span sp(*this);
		std::sort(sp.data.begin(), sp.data.end());
		for (std::vector<int>::iterator iter = sp.data.begin(); iter < sp.data.end() - 1; iter++)
		{
			if (min > *(iter + 1) - *iter)
				min = *(iter + 1) - *iter;
		}
		return min;
	}
}

int		Span::longestSpan()
{
	if (data.size() <= 1)
		throw std::logic_error("data doesn't have enough number to find longest data");
	else
	{
		int max = *(std::max_element(data.begin(), data.end()));
		int min = *(std::min_element(data.begin(), data.end()));
		return (max - min);
	}
}