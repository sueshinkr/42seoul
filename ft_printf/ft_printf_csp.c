/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/02 16:09:31 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list *ap, int *count, size_t *flag)
{
	char	buf;
	char	*temp;

	buf = va_arg(*ap, int);
	if (flag[6] > 1)
	{
		temp = (char *)calloc(flag[6], sizeof(char));
		ft_memset(temp, ' ', flag[6] - 1);
		if (flag[0] == 1)
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

char	*print_str(va_list *ap, char *buf, size_t *flag)
{
	char	*temp;

	buf = ft_strdup(va_arg(*ap, char *));
	if (!buf)
		buf = ft_strdup("(null)");
	if (flag[5] > 0 && flag[5] - 1 < ft_strlen(buf))
		buf = ft_substr(buf, 0, flag[5] - 1);
	if (flag[6] > ft_strlen(buf))
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		if (flag[0] == 1)
			buf = ft_strjoin(buf, temp);
		else
			buf = ft_strjoin(temp, buf);
	}
	return (buf);
}

char	*print_pointer(va_list *ap, char *buf, size_t *flag)
{
	unsigned long long	address;
	char				*temp;

	address = va_arg(*ap, unsigned long long);
	buf = ft_strjoin(ft_strdup("0x"), numtohex(address, 2));
	if (flag[6] > ft_strlen(buf))
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		if (flag[0] == 1)
			buf = ft_strjoin(buf, temp);
		else
			buf = ft_strjoin(temp, buf);
	}
	return (buf);
}
