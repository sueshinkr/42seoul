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
		virtual Brain*		getBrain() const;
		std::string			getType() const;
		void				setType(std::string const newtype);
};
