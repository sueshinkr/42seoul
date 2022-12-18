#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int idx = 0; idx < 4; idx++)
	{
		materia[idx] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource const& ms)
{
	for (int idx = 0; idx < 4; idx++)
	{
		if (materia[idx])
		{
			delete materia[idx];
			materia[idx] = nullptr;
		}
		if (ms.materia[idx])
			materia[idx] = ms.materia[idx]->clone();
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

MateriaSource&	MateriaSource::operator=(MateriaSource const& ms)
{
	if (this != &ms)
	{
		for (int idx = 0; idx < 4; idx++)
		{
			if (materia[idx])
			{
				delete materia[idx];
				materia[idx] = nullptr;
			}
			if (ms.materia[idx])
				materia[idx] = ms.materia[idx]->clone();
		}
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