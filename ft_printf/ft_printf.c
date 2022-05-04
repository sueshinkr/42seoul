#include <unistd.h>
#include <stdio.h>

static void select(const char *str, 가변인자)
{
	// cspdiuxX%
	if (*str == 'c')
		print_char(가변인자);
}


int ft_printf(const char *str, ...)
{
	// str은 ""으로 묶여있는 문자열. str에서 한글자씩 읽으면서 출력, %나 \만나면 따로 처리?
	while(*str)
	{
		if (*str == '"')
			str++;
		if (*str == '%')
		{
			select(++str, 가변인자);
			str++;
		}
		write(1, str++, 1);
	}
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

