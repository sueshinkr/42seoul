#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base*	generate(void)
{
	int choice = rand() % 3;

	switch(choice)
	{
		case 0:
			{
				std::cout << "Object A is selected\n";
				Base* base = new A();
				return base;
			}
		case 1:
			{
				std::cout << "Object B is selected\n";
				Base* base = new B();
				return base;
			}
		case 2:
			{
				std::cout << "Object C is selected\n";
				Base* base = new C();
				return base;
			}
	}
	return (NULL);
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "Acutal type of the object is A\n";
	else if (b)
		std::cout << "Acutal type of the object is B\n";
	else if (c)
		std::cout << "Acutal type of the object is C\n";
	else
		std::cout << "What?\n";
}

/*
void	identify(Base& p)
{

}
*/