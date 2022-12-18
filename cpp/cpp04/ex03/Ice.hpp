#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const& c);
		~Ice();
		Ice& operator=(Ice const& c);

		virtual Ice*		clone() const;
		virtual void		use(ICharacter& target);
};