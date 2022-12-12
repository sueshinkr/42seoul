#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource& ms)
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = ms.materia[idx];
	}
}

MateriaSource::~MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (materia[idx])
		{
			delete materia[idx];
			materia[idx] = nullptr;
		}
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource& ms)
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = ms.materia[idx];
	}

	return *this;
}

void		MateriaSource::learnMateria(AMateria* m)
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (materia[idx] == nullptr)
		{
			materia[idx] = m;
			return ;
		}
	}
	std::cout << "materia inventory is full\n";
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (materia[idx]->getType() == type)
		{
			return (materia[idx]->clone());
		}
	}
	return nullptr;
}