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
		Fixed& operator=(const Fixed& fx);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fx);
