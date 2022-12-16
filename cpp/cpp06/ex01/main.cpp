#include "Serial.hpp"

int	main()
{
	Data data;

	data.str = "Hello!";
	data.num = 777777;

	uintptr_t serial = Serial::serialize(&data);

	Data* deserial = Serial::deserialize(serial);
	std::cout << deserial->str << " " << deserial->num << std::endl;

	return 0;
}