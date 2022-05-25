#include "ft_printf_bonus.h"

int	cal_count_16(unsigned int n)
{
	int				count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char	*numtohex(unsigned int num, int bigorsmall)
{
	char		*hex;
	int			idx;

	idx = cal_count_16(num);
	hex = (char *)malloc((idx + 1) * sizeof(char));
	hex[idx--] = 0;
	while (idx >= 0)
	{
		if (bigorsmall == 2)
			hex[idx--] = "0123456789abcdef"[num % 16];
		else
			hex[idx--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	return (hex);
}

void	print_hex_big(va_list *ap, int *count, size_t *flag)
{
	char			*buf;
	char			*temp;

	buf = numtohex(va_arg(*ap, unsigned int), 1);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf)) // width
	{
		if (flag[0] == 1) // '-'
			buf = hex_case_minus(flag, buf, 1);
		else if (flag[1] == 1) // '0'
			buf = hex_case_zero(flag, buf, 1);
		else
			buf = hex_case_onlywidth(flag, buf, 1);
	}
	else
		buf = hex_case_nowidth(flag, buf, 1);
	write(1, buf, ft_strlen(buf));
	*count += ft_strlen(buf);
	free(buf);
}

void	print_hex_small(va_list *ap, int *count, size_t *flag)
{
	char			*buf;
	char			*temp;
 
	buf = numtohex(va_arg(*ap, unsigned int), 2);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf)) // width
	{
		if (flag[0] == 1) // '-'
			buf = hex_case_minus(flag, buf, 2);
		else if (flag[1] == 1) // '0'
			buf = hex_case_zero(flag, buf, 2);
		else
			buf = hex_case_onlywidth(flag, buf, 2);
	}
	else
		buf = hex_case_nowidth(flag, buf, 2);
	write(1, buf, ft_strlen(buf));
	*count += ft_strlen(buf);
	free(buf);
}

void	print_percent(va_list *ap, int *count, size_t *flag)
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
		write(1, buf, flag[6]);
		free(buf);
		*count += flag[6];
	}
	else
	{
		write(1, "%%", 1);
		(*count)++;
	}
}
