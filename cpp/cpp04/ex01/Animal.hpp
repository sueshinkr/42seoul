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
		Animal(Animal const& am);
		virtual ~Animal();
		Animal&	operator=(Animal const& am);

		virtual	void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
		virtual Brain*		getBrain() const;
};
