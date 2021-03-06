#include "ft_printf.h"

void	print_char(va_list *ap, int *count)
{
	char	chr;

	chr = va_arg(*ap, int);
	write(1, &chr, 1);
	(*count)++;
}

void	print_str(va_list *ap, int *count)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			(*count)++;
		}
	}
}

void	print_pointer(va_list *ap, int *count)
{
	unsigned long long	address;

	address = va_arg(*ap, unsigned long long);
	write(1, "0x", 2);
	*count += 2;
	if (!address)
	{
		write(1, "0", 1);
		(*count)++;
	}
	else
		addresstohex(address, count);
	//printf("add : %llu\n", address);

}
// unsigned long long ????

void	addresstohex(unsigned long long num, int *count)
{
	unsigned long long	temp;
	int					idx;
	char				*hex;

	idx = 0;
	temp = num;
	//printf("num : %lld\n", temp);
	//fflush(stdout);
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
	write(1, hex, temp);
	*count += temp;
	free(hex);
}
