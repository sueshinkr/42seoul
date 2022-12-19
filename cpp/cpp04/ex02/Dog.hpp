#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*		DogBrain;

	public:
		Dog();
		Dog(Dog const& dog);
		~Dog();
		Dog& operator=(Dog const& dog);

		virtual void		makeSound() const;
		virtual Brain*		getBrain() const;
};
