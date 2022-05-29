#include "ft_printf_bonus.h"

void	print_char(va_list *ap, int *count, size_t *flag)
{
	char	buf;
	char	*temp;

	buf = va_arg(*ap, int);
	if (flag[6] > 1) // width
	{
		temp = (char *)calloc(flag[6], sizeof(char));
		ft_memset(temp, ' ', flag[6] - 1);
		if (flag[0] == 1) // '-'
		{
			write(1, &buf, 1);
			write(1, temp, ft_strlen(temp));
		}
		else
		{
			write(1, temp, ft_strlen(temp));
			write(1, &buf, 1);
		}
		*count += ft_strlen(temp);
		free(temp);
	}
	else
		write(1, &buf, 1);
	(*count)++;
}

void	print_str(va_list *ap, int *count, size_t *flag)
{
	char	*buf;
	char	*temp;

	buf = ft_strdup(va_arg(*ap, char *));
	if (!buf)
	{
		write(1, "(null)", 6);
		*count += 6;
		free(buf);
		return ;
	}
	if (flag[5] > 0 && flag[5] - 1 < ft_strlen(buf)) // dop
		buf = ft_substr(buf, 0, flag[5] - 1);
	if (flag[6] > ft_strlen(buf)) // width
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		if (flag[0] == 1) // '-'
			buf = ft_strjoin(buf, temp);
		else
			buf = ft_strjoin(temp, buf);
	}
	final_print(buf, count);
}

void	print_pointer(va_list *ap, int *count, size_t *flag)
{
	unsigned long long	address;
	char	*buf;
	char	*temp;

	address = va_arg(*ap, unsigned long long);
	if (!address)
	{
		write(1, "0x0", 3);
		*count += 3;
		return ;
	}
	buf = ft_strjoin(ft_strdup("0x"), addresstohex(address));
	if (flag[6] > ft_strlen(buf)) // width
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		if (flag[0] == 1) // '-'
			buf = ft_strjoin(buf, temp);
		else
			buf = ft_strjoin(temp, buf);
	}
	final_print(buf, count);
	//printf("add : %llu\n", address);
}
// unsigned long long ????

char	*addresstohex(unsigned long long num)
{
	unsigned long long	temp;
	int					idx;
	char				*hex;

	idx = 0;
	temp = num;
	//printf("num : %llu\n", temp);
	//fflush(stdout);
	while (temp > 0)
	{
		temp /= 16;
		idx++;
	}
	hex = (char *)malloc((idx + 1) * sizeof(char));
	hex[idx--] = 0;
	while (num > 0)
	{
			hex[idx--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (hex);
}
