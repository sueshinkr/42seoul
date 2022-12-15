#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <cstring>
#include <climits>
#include "iomanip"

class Convert
{
	private:
		std::string	str;
		char*		ptr;
		double		val;

	private:
		void	type_char();
		void	type_int();
		void	type_float();
		void	type_double();

	public:
		Convert();
		Convert(char* s);
		Convert(Convert const& cv);
		~Convert();
		Convert&	operator=(Convert const& cv);

		void	Check();
};
