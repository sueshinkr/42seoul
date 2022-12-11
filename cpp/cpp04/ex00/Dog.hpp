#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string type;

	public:
		Dog();
		Dog(const Dog& dog);
		~Dog();
		Dog& operator=(const Dog& dog);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
};