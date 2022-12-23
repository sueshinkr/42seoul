#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		unsigned int n;
		std::vector<int> data;
	
	public:
		Span();
		Span(unsigned int N);
		Span(Span const& sp);
		~Span();
		Span&	operator=(Span const& sp);

		void	addNumber(int num);
		void	addManyNumber(unsigned int n);
		int		shortestSpan();
		int		longestSpan();

};