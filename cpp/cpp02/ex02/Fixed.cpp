#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_bits = 8;

/*----------------------------
	Orthodox Canonical Form
-----------------------------*/

Fixed::Fixed() : fixed_value(0)
{
}

Fixed::Fixed(const int num)
{
	setRawBits(num << fractional_bits);
}

Fixed::Fixed(const float num)
{
	setRawBits(roundf(num * (1 << fractional_bits)));
}

Fixed::Fixed(const Fixed& fx) : fixed_value(fx.getRawBits())
{
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed& fx)
{
	if (this != &fx)
		setRawBits(fx.getRawBits());

	return *this;
}

/*------------------------------------
	Overloaded comparison operators
-------------------------------------*/

bool	Fixed::operator<(const Fixed& fx) const
{
	if (getRawBits() < fx.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator>(const Fixed& fx) const
{
	if (getRawBits() > fx.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed& fx) const
{
	if (getRawBits() <= fx.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed& fx) const
{
	if (getRawBits() >= fx.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator==(const Fixed& fx) const
{
	if (getRawBits() == fx.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed& fx) const
{
	if (getRawBits() == fx.getRawBits())
		return true;
	else
		return false;
}

/*------------------------------------
	Overloaded arithmetic operators
-------------------------------------*/

Fixed	Fixed::operator+(const Fixed& fx) const
{
	Fixed plus_Fixed(getRawBits() + fx.getRawBits());

	return plus_Fixed;
}

Fixed	Fixed::operator-(const Fixed& fx) const
{
	Fixed minus_Fixed(getRawBits() - fx.getRawBits());
	
	return minus_Fixed;
}

Fixed	Fixed::operator*(const Fixed& fx) const
{
	Fixed multiple_Fixed(toFloat() * fx.toFloat());
	
	return multiple_Fixed;
}

Fixed	Fixed::operator/(const Fixed& fx) const
{
	if (fx.getRawBits() == 0)
	{
		std::cerr << "Can't devide by 0\n";
		exit(1);
	}

	Fixed plus_Fixed(toFloat() / fx.toFloat());

	return plus_Fixed;
}

/*----------------------------------
	Overloaded inc/dec operators
-----------------------------------*/

Fixed	Fixed::operator++(int)
{
	Fixed post_Fixed(*this);

	setRawBits(getRawBits() + 1);
	
	return post_Fixed;
}

Fixed&	Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);

	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed post_Fixed(*this);

	setRawBits(getRawBits() - 1);
	
	return post_Fixed;
}

Fixed&	Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	
	return *this;
}

/*----------------------------------
	Overloaded member function
-----------------------------------*/

Fixed&			Fixed::min(Fixed& fx1, Fixed& fx2)
{
	return fx1 < fx2 ? fx1 : fx2;
}

const Fixed&	Fixed::min(const Fixed& fx1, const Fixed& fx2)
{
	return fx1 < fx2 ? fx1 : fx2;
}

Fixed&			Fixed::max(Fixed& fx1, Fixed& fx2)
{
	return fx1 > fx2 ? fx1 : fx2;
}

const Fixed&	Fixed::max(const Fixed& fx1, const Fixed& fx2)
{
	return fx1 > fx2 ? fx1 : fx2;
}

/*----------------------------------
	Class <Fixed> member function
-----------------------------------*/

int		Fixed::getRawBits(void) const
{
	return fixed_value;
}

void	Fixed::setRawBits(int const raw)
{
	fixed_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (getRawBits() >> fractional_bits);
}

/*------------------
	overloaded <<
-------------------*/

std::ostream&	operator<<(std::ostream& os, const Fixed& fx)
{
	os << fx.toFloat();
	return os;
}
