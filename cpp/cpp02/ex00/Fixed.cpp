#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fx) : fixed_value(fx.getRawBits())
{
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed&  Fixed::operator=(const Fixed& fx)
{
	std::cout << "Copy assignment operator called\n";

	if (this != &fx)
		setRawBits(fx.getRawBits());

	return *this;
}

int	 Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return fixed_value;
}

void	Fixed::setRawBits(int const raw)
{
	fixed_value = raw;
}
