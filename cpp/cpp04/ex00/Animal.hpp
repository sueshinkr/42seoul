#pragma once
#include <iostream>

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
		std::string	getType() const;
		void		setType(std::string const newtype);
};
