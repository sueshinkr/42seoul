#include <iostream>
#include "span.hpp"

int	main()
{
	Span sp1 = Span(5);
	
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	srand(time(NULL));
	unsigned int size = 10000;

	Span sp(size);

	for (unsigned int i = 0; i < size; i++)
		sp.addNumber(rand());
	
	std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "longest span : " << sp.longestSpan() << std::endl;

	return 0;
}