#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string type;

	public:
		Dog();
		Dog(Dog const& dog);
		~Dog();
		Dog& operator=(Dog const& dog);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
};
