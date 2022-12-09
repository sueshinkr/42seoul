#include "temp.h"

void print_char(va_list *ap, int *count)
{
	char	ch;

	ch = va_arg(*ap, int);
	write(1, &ch, 1);
	(*count)++;
}

void	print_str(va_list *ap, int *count)
{
	char *str;
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

void	numtohex(unsigned long long num, int sel, int *count)
{
	unsigned long long	temp;
	int					idx;
	char				*str;

	idx = 0;
	temp = num;
	while (temp > 0)
	{
		temp /= 16;
		idx++;
	}
	temp = idx;
	str = (char *)malloc(idx-- * sizeof(char));
	while (num > 0)
	{
		if (sel == 1)
			str[idx--] = "0123456789abcdef"[num % 16];
		else
			str[idx--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	write(1, str, temp);
	*count += temp;
	free(str);
}

void	print_ptr(va_list *ap, int *count)
{
	unsigned long long	addr;

	addr = va_arg(*ap, unsigned long long);
	write(1, "0x", 2);
	*count += 2;
	if (!addr)
	{
		write(1, "0", 1);
		(*count)++;
	}
	else
		numtohex(addr, 1, count);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	cal_count(long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	else if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(long long num)
{
	char	*str;
	int		count;

	count = cal_count(num);
	str = (char *)malloc((count + 1) * sizeof(char));
	*(str + count) = 0;
	if (!str)
		return (NULL);
	if (num == 0)
		*str = '0';
	else if (num < 0)
	{
		*str = '-';
		num *= -1;
	}
	while (num > 0)
	{
		*(str + --count) = num % 10 | '0';
		num /= 10;
	}
	return (str);
}

void	print_dec(va_list *ap, int *count)
{
	int 	decimal;
	char	*decimal_str;
	int 	len;

	decimal = va_arg(*ap, int);
	decimal_str = ft_itoa(decimal);
	len = ft_strlen(decimal_str);
	write(1, decimal_str, len);
	(*count) += len;
	free(decimal_str);
}

void	print_int(va_list *ap, int *count)
{
	int 	integer;
	char	*integer_str;
	int 	len;

	integer = va_arg(*ap, int);
	integer_str = ft_itoa(integer);
	len = ft_strlen(integer_str);
	write(1, integer_str, len);
	(*count) += len;
	free(integer_str);
}

void	print_udec(va_list *ap, int *count)
{
	int 	udecimal;
	char	*udecimal_str;
	int 	len;

	udecimal = va_arg(*ap, unsigned int);
	udecimal_str = ft_itoa(udecimal);
	len = ft_strlen(udecimal_str);
	write(1, udecimal_str, len);
	(*count) += len;
	free(udecimal_str);
}

void	print_hex(va_list *ap, int *count)
{
	unsigned long long	num;

	num = va_arg(*ap, unsigned long long);
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	numtohex(num, 1, count);
}

void	print_HEX(va_list *ap, int *count)
{
	unsigned long long	num;

	num = va_arg(*ap, unsigned long long);
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	numtohex(num, 2, count);
}