#include "ft_printf_bonus.h"

int	cal_count(long long n)
{
	int				count;

	count = 0;
	if (n == 0)
		count++;
	else if (n < 0)
		n = n * -1;
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
	int		minus;
	char	*temp;
	char	*buf;

	minus = 0;
	buf = ft_itoa(va_arg(*ap, int), &minus);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if ((minus == 0 && flag[6] > ft_strlen(buf)) ||
		(minus == 1 && flag[6] > ft_strlen(buf) + 1)) // width
	{
		if (flag[0] == 1) // '-'
			buf = number_case_minus(flag, buf, minus);
		else if (flag[1] == 1 && flag[5] == 0) // '0'
			buf = number_case_zero(flag, buf, minus);
		else
			buf = number_case_onlywidth(flag, buf, minus);
	}
	else
		buf = number_case_nowidth(flag, buf, minus);
	final_print(buf, count);
}

void	print_integer(va_list *ap, int *count, size_t *flag)
{
	int		minus;
	char	*temp;
	char	*buf;
	
	minus = 0;
	buf = ft_itoa(va_arg(*ap, int), &minus);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if ((minus == 0 && flag[6] > ft_strlen(buf)) ||
		(minus == 1 && flag[6] > ft_strlen(buf) + 1)) // width
	{
		if (flag[0] == 1) // '-'
			buf = number_case_minus(flag, buf, minus);
		else if (flag[1] == 1 && flag[5] == 0) // '0'
			buf = number_case_zero(flag, buf, minus);
		else
			buf = number_case_onlywidth(flag, buf, minus);
	}
	else
		buf = number_case_nowidth(flag, buf, minus);
	final_print(buf, count);
}

void	print_unsigned_decimal(va_list *ap, int *count, size_t *flag)
{
	char	*temp;
	char	*buf;
	
	buf = ft_uitoa(va_arg(*ap, unsigned int));
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf)) // width
	{
		if (flag[0] == 1) // '-'
			buf = number_case_minus(flag, buf, 0);
		else if (flag[1] == 1 && flag[5] == 0) // '0'
			buf = number_case_zero(flag, buf, 0);
		else
			buf = number_case_onlywidth(flag, buf, 0);
	}
	else
		buf = number_case_nowidth(flag, buf, 0);
	final_print(buf, count);
}
