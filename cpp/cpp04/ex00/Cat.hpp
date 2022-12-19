#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat(Cat const& Cat);
		~Cat();
		Cat& operator=(Cat const& Cat);

		virtual void	makeSound() const;
};
