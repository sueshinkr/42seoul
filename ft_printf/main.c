#include "ft_printf.h"

int main()
{
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

	//ft_printf("abcdefg%c%s", chr, str);
	return (0);
}
