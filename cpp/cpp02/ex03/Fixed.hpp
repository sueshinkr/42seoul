#pragma once
#include <iostream>

class Fixed
{
	private:
		int fixed_value;
		static const int fractional_bits;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fx);
		Fixed&	operator=(const Fixed& fx);
		~Fixed();

		bool	operator<(const Fixed& fx) const;
		bool	operator>(const Fixed& fx) const;
		bool	operator<=(const Fixed& fx) const;
		bool	operator>=(const Fixed& fx) const;
		bool	operator==(const Fixed& fx) const;
		bool	operator!=(const Fixed& fx) const;

		Fixed	operator+(const Fixed& fx) const;
		Fixed	operator-(const Fixed& fx) const;
		Fixed	operator*(const Fixed& fx) const;
		Fixed	operator/(const Fixed& fx) const;

		Fixed	operator++(int);
		Fixed&	operator++(void);
		Fixed	operator--(int);
		Fixed&	operator--(void);

		static Fixed& 		min(Fixed& fx1, Fixed& fx2);
		static const Fixed& min(const Fixed& fx1, const Fixed& fx2);
		static Fixed& 		max(Fixed& fx1, Fixed& fx2);
		static const Fixed& max(const Fixed& fx1, const Fixed& fx2);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fx);
