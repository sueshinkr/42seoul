#include "Convert.hpp"

Convert::Convert() : val(0.0)
{
}

Convert::Convert(char* s) : str(s), ptr(nullptr)
{
	if (str.length() == 1 && !isdigit(str[0]))
		val = static_cast<double>(str[0]);
	else
		val = std::strtod(s, &ptr);
}

Convert::Convert(Convert const& cv) : ptr(cv.ptr), val(cv.val)
{
}

Convert::~Convert()
{
}

Convert&	Convert::operator=(Convert const& cv)
{
	if (this != &cv)
	{
		val = cv.val;
	}

	return *this;
}

void	Convert::Check()
{
	try
	{
		if (ptr && *ptr && !(std::isinf(val) || *ptr == 'f'))
				throw std::bad_alloc();
		type_char();
		type_int();
		type_float();
		type_double();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Convert::type_char()
{
	char c = static_cast<char>(val);
	std::cout << "char : ";
	if (std::isnan(val) || std::isinf(val) || val > 127 || val < 0)
		std::cout << "impossible\n";
	else if (std::isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable\n";
}

void	Convert::type_int()
{
	int i = static_cast<int>(val);
	std::cout << "int : ";
	if (val > INT_MAX || val < INT_MIN || std::isnan(val) || std::isinf(val))
		std::cout << "impossible\n";
	else
		std::cout << i << std::endl;
}

void	Convert::type_float()
{
	float f = static_cast<float>(val);
	std::cout << "float : ";
	if (std::isnan(val))
		std::cout << f << "f" << std::endl;
	else if (std::isinf(val))
		std::cout << std::showpos << f << "f" << std::endl;
	else if (f == static_cast<int>(f) && str.length() <= 6)
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f << "f" << std::endl;
}

void	Convert::type_double()
{	
	std::cout << "double : ";
	if (std::isnan(val))
		std::cout << val << std::endl;
	else if (std::isinf(val))
		std::cout << std::showpos << val << std::endl;
	else if (val == static_cast<int>(val))
		std::cout << val << ".0" << std::endl;
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << val << std::endl;
}
