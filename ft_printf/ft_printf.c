#include "ft_printf.h"
#include "libft.h"

static void	addresstohex(long long num, int *count)
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
	while (*str)
	{
		write(1, str++, 1);
		(*count)++;
	}
}

static void	print_pointer(va_list *ap, int *count)
{
	int	address;

	address = va_arg(*ap, long long);
	addresstohex(address, count);
}

static void print_decimal(va_list *ap)
{
	int	decimal;
	decimal = va_arg(*ap, int);
	itoa(decimal);
}

static void select_format(const char *str, va_list *ap)
{
	// cspdiuxX%
	if (*str == 'c')
		print_char(ap, count);
	else if (*str == 's')
		print_str(ap, count);
	else if (*str == 'p')
		print_pointer(ap, count);
	else if (*str == 'd')
		print_decimal(ap);
	else if (*str == 'i') // scanf시에는 8, 10, 16진법을 입력받음. 출력시에는 %d와 차이 없음
		print_int(ap);
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

