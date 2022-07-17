/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/04 16:14:11 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list *ap, int *count, t_flag flag)
{
	char	buf;
	char	*temp;

	buf = va_arg(*ap, int);
	if (flag.width > 1)
	{
		temp = ft_calloc(flag.width, sizeof(char));
		ft_memset(temp, ' ', flag.width - 1);
		if (flag.minus == 1)
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

char	*print_str(va_list *ap, char *buf, t_flag flag)
{
	char	*temp;
	size_t	len;

	buf = ft_strdup(va_arg(*ap, char *));
	if (!buf)
		buf = ft_strdup("(null)");
	if (flag.pcs > 0 && flag.pcs - 1 < ft_strlen(buf))
		buf = ft_substr(buf, 0, flag.pcs - 1);
	len = ft_strlen(buf);
	if (flag.width > len)
	{
		temp = ft_calloc(flag.width - len + 1, sizeof(char));
		ft_memset(temp, ' ', flag.width - len);
		if (flag.minus == 1)
			buf = ft_strjoin(buf, temp);
		else
			buf = ft_strjoin(temp, buf);
	}
	return (buf);
}

char	*print_pointer(va_list *ap, char *buf, t_flag flag)
{
	unsigned long long	address;
	char				*temp;
	size_t				len;

	address = va_arg(*ap, unsigned long long);
	buf = ft_strjoin(ft_strdup("0x"), numtohex(address, 0, 2));
	len = ft_strlen(buf);
	if (flag.width > len)
	{
		temp = ft_calloc(flag.width - len + 1, sizeof(char));
		ft_memset(temp, ' ', flag.width - len);
		if (flag.minus == 1)
			buf = ft_strjoin(buf, temp);
		else
			buf = ft_strjoin(temp, buf);
	}
	return (buf);
}
