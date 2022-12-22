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
	if (dynamic_cast<A*>(p))
		std::cout << "Acutal type of the object is A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Acutal type of the object is B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Acutal type of the object is C\n";
	else
		std::cout << "What?\n";
}

void	identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Acutal type of the object is A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout << "Acutal type of the object is B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				static_cast<void>(dynamic_cast<C&>(p));
				std::cout << "Acutal type of the object is C\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}
