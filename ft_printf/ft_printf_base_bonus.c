#include "ft_printf_bonus.h"

int	dop(char **str)
{
	int	dop;

	dop = 0;
	(*str)++;
	if (*(*str) >= '0' && *(*str) <= '9')
	{
		while (*(*str) >= '0' && *(*str) <= '9')
		{
			dop = dop * 10 + *(*str) - '0';
			(*str)++;
		}
		(*str)--;
		return (dop);
	}
	(*str)--;
	return (1);
}

int	width(char **str)
{
	int	width;

	width = 0;
	{
		while (*(*str) >= '0' && *(*str) <= '9')
		{
			width = width * 10 + *(*str) - '0';
			(*str)++;
		}
		(*str)--;
	}
	return (width);
}


void	select_flag(char **str, va_list *ap, int *count)
{
	size_t	flag[7];

	ft_memset(flag, 0, sizeof(flag));
	while (!ft_strchr("cspdiuxX%%", *(*str)))
	{
		if (*(*str) == '-')
			flag[0] = 1;
		else if (*(*str) == '0')
			flag[1] = 1;
		else if (*(*str) == '#')
			flag[2] = 1;
		else if (*(*str) == ' ')
			flag[3] = 1;
		else if (*(*str) == '+')
			flag[4] = 1;
		else if (*(*str) == '.')
			flag[5] = dop(str);
		else
			flag[6] = width(str);
		(*str)++;
	}
	select_format(str, ap, count, flag);
//%[플래그][폭][.정밀도][길이]서식지정자
}

void	select_format(char **str, va_list *ap, int *count, size_t *flag)
{
	if (*(*str) == 'c')
		print_char(ap, count, flag);
	else if (*(*str) == 's')
		print_str(ap, count, flag);
	else if (*(*str) == 'p')
		print_pointer(ap, count, flag);
	else if (*(*str) == 'd')
		print_decimal(ap, count, flag);
	else if (*(*str) == 'i')
		print_integer(ap, count, flag);
	else if (*(*str) == 'u')
		print_unsigned_decimal(ap, count, flag);
	else if (*(*str) == 'x')
		print_hex_small(ap, count, flag);
	else if (*(*str) == 'X')
		print_hex_big(ap, count, flag);
	else if (*(*str) == '%')
		print_percent(ap, count, flag);
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
			str++;
			select_flag(&(str), &ap, &count);
			//select_format(++str, &ap, &count);
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

/*

"-0# +."

1. 문자열 읽으면서 %찾기
2. %찾으면 플래그찾기로 이동
3. 각각의 플래그 존재여부 및 폭, 정밀도 저장
4. 서식 찾기, 각 서식에 따른 문자열 저장
5. 서식에 따라 필요한 플래그를 구별하고, 해당 플래그 존재여부에 따라 기존 문자열과 합침
6. 완성된 문자열 반환 및 카운트 올리기
*/ 
