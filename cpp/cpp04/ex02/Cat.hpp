#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*		CatBrain;

	public:
		Cat();
		Cat(Cat const& Cat);
		~Cat();
		Cat& operator=(Cat const& Cat);

		virtual void		makeSound() const;
		virtual Brain*		getBrain() const;
};
