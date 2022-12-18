#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		std::string	type;
		Brain*		DogBrain;

	public:
		Dog();
		Dog(Dog const& dog);
		~Dog();
		Dog& operator=(Dog const& dog);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
		virtual Brain*		getBrain() const;
};
