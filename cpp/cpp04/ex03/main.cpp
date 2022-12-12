#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	AMateria* tmp[5];
	tmp[0] = src->createMateria("ice");
	me->equip(tmp[0]);
	tmp[1] = src->createMateria("ice");
	me->equip(tmp[1]);
	tmp[2] = src->createMateria("cure");
	me->equip(tmp[2]);
	tmp[3] = src->createMateria("cure");
	me->equip(tmp[3]);

	tmp[4] = src->createMateria("cure");
	me->equip(tmp[4]);
	me->unequip(0);
	delete tmp[0];
	me->equip(tmp[4]);
 
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}