#include "ft_printf.h"

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
	//printf("\n%d\n", printf("123%d123%2147483646d", 10, 10));
	printf("\n%d\n", printf("123%d123%5d", 10, 10));
	int n = printf("Hello %.2147483647d", 42);
	//ft_printf("abcdefg%c%s", chr, str);
	*/
	printf("1.%d::\n", printf("!%c", '0'));
	fflush(stdout);
	printf("2.%d::\n", ft_printf("!%c", '0'));

/*
	printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", '0', 0, '1');
	printf(" %c %c %c \n", ' ', ' ', ' ');
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
*/
	return (0);
}
