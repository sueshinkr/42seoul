#pragma once
#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string newtype);
		Animal(const Animal& am);
		virtual ~Animal();
		Animal&	operator=(const Animal& am);

		virtual	void		makeSound() const = 0;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
		virtual Brain*		getBrain() const = 0;
};
