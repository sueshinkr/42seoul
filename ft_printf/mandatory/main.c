#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	//ft_printf("%p %x\n", 0, 0);
	//printf("p:%.0d\n", 0);
	//printf("%.4s", NULL);
	//ft_printf("%.4s", NULL);
	//printf("p; %.8u %.9u %.10u %.11u %.12u %.13u %.14u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//ft_printf("f: %.8u %.9u %.10u %.11u %.12u %.13u %.14u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("%c\n", 'a');
	ft_printf("%s\n", "123456");
	ft_printf("%p\n", "123456");
	ft_printf("%d\n", -123456);
	ft_printf("%d %d %d\n", 0, -1, 1);
	ft_printf("%x\n", 123456);
	ft_printf("%X\n", 123456);
	ft_printf("%%\n");
	//system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	//system("leaks a.out");
	return (0);
}
