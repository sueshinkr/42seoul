#include "Base.hpp"

int	main()
{
	srand(time(NULL));

	Base* random_base = generate();
	identify(random_base);

	return 0;
}