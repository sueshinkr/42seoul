#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog();
		Dog(Dog const& dog);
		~Dog();
		Dog& operator=(Dog const& dog);

		virtual void	makeSound() const;
};
