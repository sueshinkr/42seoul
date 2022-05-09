#include "ft_printf.h"
#include "libft.h"

static void	addresstohex(unsigned long long num, int *count)
{
	unsigned long long	temp;
	int			idx;
	char		*hex;

	idx = 0;
	temp = num;
	//printf("num : %lld\n", temp);
	//fflush(stdout);
	while (temp > 0)
	{
		temp /= 16;
		idx++;
	}
	temp = idx;
	hex = (char *)malloc(idx-- * sizeof(char));
	while (num > 0)
	{
			hex[idx--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	write(1, "0x", 2);
	write(1, hex, temp);
	*count += (2 + temp);
	free(hex);
}

static void	numtohex(long long num, int bigorsmall, int *count)
{
	long long	temp;
	int			idx;
	char		*hex;

	idx = 0;
	temp = num;
	while (temp > 0)
	{
		temp /= 16;
		idx++;
	}
	temp = idx;
	hex = (char *)malloc(idx-- * sizeof(char));
	while (num > 0)
	{
		if (bigorsmall == 2)
			hex[idx--] = "0123456789abcdef"[num % 16];
		else
			hex[idx--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	write(1, hex, temp);
	*count += temp;
	free(hex);
}

static void	print_char(va_list *ap, int *count)
{
	char	chr;

	chr = va_arg(*ap, int);
	write(1, &chr, 1);
	(*count)++;
}

static void	print_str(va_list *ap, int *count)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			(*count)++;
		}
	}
}

static void	print_pointer(va_list *ap, int *count)
{
	unsigned long long	address;

	address = va_arg(*ap, unsigned long long);
	if (!address)
	{
		write(1, "(nil)", 5);
		*count += 5;
	}
	else
	//printf("add : %llu\n", address);
		addresstohex(address, count);
}
// unsigned long long ????

static void	print_decimal(va_list *ap, int *count)
{
	int		decimal;
	int		idx;
	char	*decimal_char;
	
	idx = 0;
	decimal = va_arg(*ap, int);
	decimal_char = ft_itoa(decimal);
	while (*(decimal_char + idx))
	{
		write(1, decimal_char + idx++, 1);
		(*count)++;
	}
	free(decimal_char);
}

static void	print_integer(va_list *ap, int *count)
{
	int		integer;
	int		idx;
	char	*integer_char;
	
	idx = 0;
	integer = va_arg(*ap, int);
	integer_char = ft_itoa(integer);
	while (*(integer_char + idx))
	{
		write(1, integer_char + idx++, 1);
		(*count)++;
	}
	free(integer_char);
}

static void	print_unsigned_decimal(va_list *ap, int *count)
{
	unsigned int	unsigned_decimal;
	int				idx;
	char			*unsigned_decimal_char;
	
	idx = 0;
	unsigned_decimal = va_arg(*ap, int);
	unsigned_decimal_char = ft_itoa(unsigned_decimal);
	while (*(unsigned_decimal_char + idx))
	{
		write(1, unsigned_decimal_char + idx++, 1);
		(*count)++;
	}
	free(unsigned_decimal_char);
}

static void	print_hex_small(va_list *ap, int *count)
{
	unsigned int	num;
 
	num = va_arg(*ap, unsigned int);
	numtohex(num, 2, count);
}

static void	print_hex_big(va_list *ap, int *count)
{
	unsigned int	num;
 
	num = va_arg(*ap, unsigned int);
	numtohex(num, 1, count);
}

static void select_format(const char *str, va_list *ap, int *count)
{
	// c(ok) s(ok) p(ok) d i u x X %(ok)
	if (*str == 'c')
		print_char(ap, count);
	else if (*str == 's')
		print_str(ap, count);
	else if (*str == 'p')
		print_pointer(ap, count);
	else if (*str == 'd')
		print_decimal(ap, count);
	else if (*str == 'i')
		print_integer(ap, count);
	else if (*str == 'u')
		print_unsigned_decimal(ap, count);
	else if (*str == 'x')
		print_hex_small(ap, count);
	else if (*str == 'X')
		print_hex_big(ap, count);
	else if (*str == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	return ;
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int		count;

	count = 0;
	va_start(ap, str);
	// str은 ""으로 묶여있는 문자열. str에서 한글자씩 읽으면서 출력, %나 \만나면 따로 처리?
	while(*str)
	{
		if (*str == '"')
			str++;
		else if (*str == '%')
		{
			select_format(++str, &ap, &count);
			str++;
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}


/*
가변인자
va_start: 가변 인자를 가져올 수 있도록 포인터를 설정합니다.
va_copy : 가변 인자 포인터 복사	
va_arg: 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옵니다.
va_end: 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화합니다.
"" : 문자열 상수
printf("hello %s, %d\n", str, num);


*/

