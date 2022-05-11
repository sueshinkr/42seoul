#include "ft_printf.h"

/*
static void select_flag(const char *str, va_list *ap, int *count)
{

}
*/

void select_format(const char *str, va_list *ap, int *count)
{
	//if (ft_strchr("-0.# +", *str))
	//	select_flag(str, ap, count);
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

