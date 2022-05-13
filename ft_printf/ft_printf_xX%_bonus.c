#include "ft_printf_bonus.h"
#include "libft.h"

int	cal_count_16(unsigned int n)
{
	int				count;

	count = -1;
	if (n == 0)
		count++;
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

void	print_hex_small(va_list *ap, int *count, int *flag)
{
	unsigned int	num;
	char			*buf;
	char			*temp;
 
	num = va_arg(*ap, unsigned int);
	buf = numtohex(num, 2);
	if (flag[5] > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf)) // width
	{
		if (flag[0] == 1) // '-'
		{
			if (flag[2] == 1 && ft_atoi(buf)) // '#'
				buf = ft_strjoin(ft_strdup("0x"), buf);
			if (flag[6] > ft_strlen(buf))
			{
				temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
				ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
				buf = ft_strjoin(buf, temp);
			}
		}
		else if (flag[1] == 1) // '0'
		{
			if (flag[5] > 0) // dop
			{
				if (flag[2] == 1) // '#'
					buf = ft_strjoin(ft_strdup("0x"), buf);
				temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
				ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
				buf = ft_strjoin(temp, buf);
			}
			else
			{
				if (flag[2] == 1) // #
				{
					temp = (char *)calloc(flag[6] - ft_strlen(buf) - 1, sizeof(char)); 
					ft_memset(temp, '0', flag[6] - ft_strlen(buf) - 2);
					buf = ft_strjoin(temp, buf);
					buf = ft_strjoin(ft_strdup("0x"), buf);
				}
				else
				{
					temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
					ft_memset(temp, '0', flag[6] - ft_strlen(buf));
					buf = ft_strjoin(temp, buf);
				}
			}
		}
	}
	else
	{
		if (flag[2] == 1 && ft_atoi(buf))
			buf = ft_strjoin(ft_strdup("0x"), buf);
	}
	write(1, buf, ft_strlen(buf));
	*count += ft_strlen(buf);
	free(buf);
}

void	print_hex_big(va_list *ap, int *count, int *flag)
{
	unsigned int	num;
	char			*buf;
	char			*temp;
 
	num = va_arg(*ap, unsigned int);
	buf = numtohex(num, 1);
	if (flag[5] > ft_strlen(buf)) // dop
	{
		temp = (char *)calloc(flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf)) // width
	{
		if (flag[0] == 1) // '-'
		{
			if (flag[2] == 1 && ft_atoi(buf)) // '#'
			// atoi 16진수버전 만들기
			// libft 귀찮은데 버리기?
				buf = ft_strjoin(ft_strdup("0x"), buf);
			if (flag[6] > ft_strlen(buf))
			{
				temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
				ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
				buf = ft_strjoin(buf, temp);
			}
		}
		else if (flag[1] == 1) // '0'
		{
			if (flag[5] > 0) // dop
			{
				if (flag[2] == 1) // '#'
					buf = ft_strjoin(ft_strdup("0x"), buf);
				temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
				ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
				buf = ft_strjoin(temp, buf);
			}
			else
			{
				if (flag[2] == 1) // #
				{
					temp = (char *)calloc(flag[6] - ft_strlen(buf) - 1, sizeof(char)); 
					ft_memset(temp, '0', flag[6] - ft_strlen(buf) - 2);
					buf = ft_strjoin(temp, buf);
					buf = ft_strjoin(ft_strdup("0x"), buf);
				}
				else
				{
					temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
					ft_memset(temp, '0', flag[6] - ft_strlen(buf));
					buf = ft_strjoin(temp, buf);
				}
			}
		}
	}
	else
	{
		if (flag[2] == 1 && ft_atoi(buf))
			buf = ft_strjoin(ft_strdup("0x"), buf);
	}
		write(1, buf, ft_strlen(buf));
		*count += ft_strlen(buf);
		free(buf);
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
