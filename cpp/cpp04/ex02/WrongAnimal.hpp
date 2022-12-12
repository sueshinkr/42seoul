#pragma once
#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string newtype);
		WrongAnimal(const WrongAnimal& am);
		virtual ~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& am);

		void		makeSound() const;
		std::string	getType() const;
		void		setType(std::string const newtype);
};
