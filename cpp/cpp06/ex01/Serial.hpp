#include <iostream>

struct Data
{
	std::string str;
	int			num;
};

class Serial
{
	private:
//uintptr_t	u_int;
//Data*		data_ptr;

	public:
		Serial();
		Serial(Serial const& s);
		~Serial();
		Serial&	operator=(Serial const& s);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};