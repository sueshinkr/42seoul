#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_value = 0;
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

Fixed&  Fixed::operator=(const Fixed& fx)
{
	std::cout << "Copy assignment operator called\n";

	if (this != &fx)
		fixed_value = fx.getRawBits();

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
