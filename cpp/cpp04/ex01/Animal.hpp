#pragma once
#include <iostream>

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

		virtual	void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
};
