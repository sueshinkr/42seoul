#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	materia[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& ms);
		~MateriaSource();
		MateriaSource& operator=(MateriaSource const& ms);

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const& type);
}; 