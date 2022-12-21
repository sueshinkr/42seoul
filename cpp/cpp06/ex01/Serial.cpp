#include "Serial.hpp"

Serial::Serial()
{
}

Serial::Serial(Serial const& s)
{
	static_cast<void>(s);
}

Serial::~Serial()
{

}

Serial&		Serial::operator=(Serial const& s)
{
	static_cast<void>(s);
	return *this;
}

uintptr_t	Serial::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serial::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}