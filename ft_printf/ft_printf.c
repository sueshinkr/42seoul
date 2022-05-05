#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static void	itohex(int num)
{
	int	temp;
	int	count;
	char	*hex;

	count = 0;
	temp = num;
	while (temp > 0)
	{
		temp /= 16;
		count++;
	}
	temp = count;
	hex = (char *)malloc(count-- * sizeof(char));
	while (num > 0)
	{
		hex[count--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	write(1, hex, temp);
	free(hex);
}

static void	print_char(va_list *ap)
{
	char	chr;

	chr = va_arg(*ap, int);
	write(1, &chr, 1);
}

static void	print_str(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	while (*str)
		write(1, str++, 1);
}

static void	print_pointer(va_list *ap)
{
	int address;

	address = va_arg(*ap, int);
	itohex(address);
}

static void select_format(const char *str, va_list *ap)
{
	// cspdiuxX%
	if (*str == 'c')
		print_char(ap);
	else if (*str == 's')
		print_str(ap);
	else if (*str == 'p')
		print_pointer(ap);
/*
	else if (*str == 'd')
		print_decimal(ap);
	else if (*str == 'i')
		print_int(ap);
	else if (*str == 'u')
		print_unsigned_decimal(ap);
	else if (*str == 'x')
		print_hex_small(ap);
	else if (*str == 'X')
		print_hex_big(ap);
	else if (*str == '%')
		print_(ap);
	*/
return ;
}

int ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	// str은 ""으로 묶여있는 문자열. str에서 한글자씩 읽으면서 출력, %나 \만나면 따로 처리?
	while(*str)
	{
		if (*str == '"')
			str++;
		else if (*str == '%')
		{
			select_format(++str, &ap);
			str++;
		}
		else
			write(1, str++, 1);
	}
	va_end(ap);
	return (0);
}

int main()
{
	char chr = '!';
	char str[1000] = "12345";

	ft_printf("abcdefg %s %c %p", str, chr, str);
	//ft_printf("abcdefg%c%s", chr, str);
	return (0);
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

