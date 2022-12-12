#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string type;
		Brain*		CatBrain;

	public:
		Cat();
		Cat(const Cat& Cat);
		~Cat();
		Cat& operator=(const Cat& Cat);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
		virtual void		setType(std::string const newtype);
		virtual Brain*		getBrain() const;
};
