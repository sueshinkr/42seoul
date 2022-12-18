#pragma once
#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string newtype);
		WrongAnimal(WrongAnimal const& am);
		virtual ~WrongAnimal();
		WrongAnimal&	operator=(WrongAnimal const& am);

		void		makeSound() const;
		std::string	getType() const;
		void		setType(std::string const newtype);
};
