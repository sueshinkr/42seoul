#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& c);
		~Cure();
		Cure& operator=(const Cure& c);

		virtual Cure*		clone() const;
		virtual void		use(ICharacter& target);
};