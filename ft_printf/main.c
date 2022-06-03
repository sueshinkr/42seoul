#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//ft_printf("%p %x\n", 0, 0);
	//printf("p:%.0d\n", 0);
	printf("%p", NULL);
	ft_printf("%p", NULL);


	//system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	//system("leaks a.out");
	return (0);
}
