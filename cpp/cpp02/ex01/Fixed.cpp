#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	fixed_value = num << fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	fixed_value = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& fx) : fixed_value(fx.fixed_value)
{
	std::cout << "Copy constructor called\n";
	fixed_value = fx.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& fx)
{
	std::cout << "Copy assignment operator called\n";

	if (this != &fx)
		fixed_value = fx.getRawBits();

	return *this;
}

int		Fixed::getRawBits(void) const
{
	return fixed_value;
}

void	Fixed::setRawBits(int const raw)
{
	fixed_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_value) / (1 << fractional_bits));
}

int Fixed::toInt(void) const
{
	return (fixed_value >> fractional_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return os;
}
