#include <iostream>

struct Data
{
	std::string str;
	int			num;
};

class Serial
{
	private:

	public:
		Serial();
		Serial(Serial const& s);
		~Serial();
		Serial&	operator=(Serial const& s);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};