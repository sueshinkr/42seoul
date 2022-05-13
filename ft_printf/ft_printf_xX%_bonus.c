#include "ft_printf.h"
#include "libft.h"

void	numtohex(long long num, int bigorsmall, int *count)
{
	long long	temp;
	int			idx;
	char		*hex;

	idx = 0;
	temp = num;
	while (temp > 0)
	{
		temp /= 16;
		idx++;
	}
	temp = idx;
	hex = (char *)malloc(idx-- * sizeof(char));
	while (num > 0)
	{
		if (bigorsmall == 2)
			hex[idx--] = "0123456789abcdef"[num % 16];
		else
			hex[idx--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	write(1, hex, temp);
	*count += temp;
	free(hex);
}

void	print_hex_small(va_list *ap, int *count)
{
	unsigned int	num;
 
	num = va_arg(*ap, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	numtohex(num, 2, count);
}

void	print_hex_big(va_list *ap, int *count)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	numtohex(num, 1, count);
}

void	print_percent(va_list *ap, int *count, int *flag)
{
	char	*buf;

	if (flag[6] > 1) // width
	{
		buf = (char *)malloc(flag[6] * sizeof(char));
		if (flag[0] == 1) // '-'
		{
			ft_memset(buf, ' ', sizeof(buf));
			buf[0] = '%';
		}
		else if (flag[1] == 1) // '0'
		{
			ft_memset(buf, '0', sizeof(buf));
			buf[flag[6] - 1] = '%';
		}
	}
	write(1, buf, flag[6]);
	free(buf);
	*count += flag[6];
}
