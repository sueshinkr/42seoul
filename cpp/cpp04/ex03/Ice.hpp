#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& c);
		~Ice();
		Ice& operator=(const Ice& c);

		virtual Ice*		clone() const;
		virtual void		use(ICharacter& target);
};