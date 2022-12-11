#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string type;

	public:
		Cat();
		Cat(const Cat& Cat);
		~Cat();
		Cat& operator=(const Cat& Cat);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
};
