#include "ft_printf_bonus.h"

int	cal_count(long long n)
{
	int				count;

	count = 0;
	if (n <= 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char		*str;
	int			count;
	long long	nb;

	nb = n;
	count = cal_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	*(str + count) = 0;
	while (nb > 0)
	{
		*(str + --count) = nb % 10 | '0';
		nb /= 10;
	}
	return (str);
}

void	print_decimal(va_list *ap, int *count, size_t *flag)
{
	int		decimal;
	int		idx;
	char	*decimal_char;

	idx = 0;
	decimal = va_arg(*ap, int);
	decimal_char = ft_itoa(decimal);
	while (*(decimal_char + idx))
	{
		write(1, decimal_char + idx++, 1);
		(*count)++;
	}
	free(decimal_char);
}

void	print_integer(va_list *ap, int *count, size_t *flag)
{
	int		integer;
	int		idx;
	char	*integer_char;

	idx = 0;
	integer = va_arg(*ap, int);
	integer_char = ft_itoa(integer);
	while (*(integer_char + idx))
	{
		write(1, integer_char + idx++, 1);
		(*count)++;
	}
	free(integer_char);
}

void	print_unsigned_decimal(va_list *ap, int *count, size_t *flag)
{
	unsigned int	unsigned_decimal;
	int				idx;
	char			*unsigned_decimal_char;

	idx = 0;
	unsigned_decimal = va_arg(*ap, int);
	unsigned_decimal_char = ft_uitoa(unsigned_decimal);
	while (*(unsigned_decimal_char + idx))
	{
		write(1, unsigned_decimal_char + idx++, 1);
		(*count)++;
	}
	free(unsigned_decimal_char);
}
