#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string type;

	public:
		WrongCat();
		WrongCat(WrongCat const& WrongCat);
		~WrongCat();
		WrongCat& operator=(WrongCat const& WrongCat);

		void		makeSound();
		std::string	getType() const;
		void		setType(std::string const newtype);
};
