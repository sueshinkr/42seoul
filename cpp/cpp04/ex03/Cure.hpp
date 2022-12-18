#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const& c);
		~Cure();
		Cure& operator=(Cure const& c);

		virtual Cure*		clone() const;
		virtual void		use(ICharacter& target);
};