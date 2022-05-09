#include "ft_printf.h"
#include <limits.h>

int main()
{
/*
	char chr = '!';
	char str[1000] = "12345";
	int	num = 777777;

	ft_printf("abcdefg %s :: %c :: %p :: %d", str, chr, str, num);
	printf("\n");
	printf("abcdefg %s :: %c :: %p :: %d", str, chr, str, num);
	printf("\n");
	ft_printf("%i :: %x :: %X :: %%", num, num, num);
	printf("\n");
	printf("%i :: %x :: %X :: %%", num, num, num);
	printf(":::\n");
	printf("\n%d\n", printf("123%d123%2147483646d", 10, 10));
	printf("\n%d\n", printf("123%d123%5d", 10, 10));
	int n = printf("Hello %.2147483647d", 42);
	//ft_printf("abcdefg%c%s", chr, str);
*/

/*
	printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf(" %p ", -1);
	printf(" %p %p ", 0, 0);
	fflush(stdout);
	printf("\n");
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	ft_printf(" %p ", -1);
	ft_printf(" %p %p ", 0, 0);
*/

/*
	printf("1.%d::\n", printf("!%c", '0'));
	printf(" %c %c %c \n", '0', 0, '1');
	printf(" %c %c %c \n", ' ', ' ', ' ');
	fflush(stdout);
	ft_printf("2.%d::\n", ft_printf("!%c", '0'));
	ft_printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
*/
	printf("\n%d\n", printf("123%d123%d", 10, -10));
	ft_printf("\n%d\n", ft_printf("123%d123%d", 10, -10));
	return (0);
}
