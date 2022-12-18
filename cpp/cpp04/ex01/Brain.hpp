#pragma once
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(Brain const& brain);
		~Brain();
		Brain& operator=(Brain const& brain);

		std::string	getIdea(int idx);
		void		setIdea(std::string idea, int idx);
};
