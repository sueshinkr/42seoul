#include "Base.hpp"

int	main()
{
	srand(clock());

	Base* random_base = generate();
	identify(random_base);

	Base& random_base_reference = *random_base;
	identify(random_base_reference);

	return 0;
}