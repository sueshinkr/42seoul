#pragma once
#include <iostream>

class Fixed
{
	private:
		int					fixed_value;
		static const int	fractional_bits;
	
	public:
		Fixed();
		Fixed(const Fixed&);
		~Fixed();
		Fixed& operator=(const Fixed&);


		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};
