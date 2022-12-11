#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string type;

	public:
		WrongCat();
		WrongCat(const WrongCat& WrongCat);
		~WrongCat();
		WrongCat& operator=(const WrongCat& WrongCat);

		void				makeSound();
		std::string	getType() const;
		void		setType(std::string const newtype);
};
