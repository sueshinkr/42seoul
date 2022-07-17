/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:36:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/04 16:14:30 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hex_big(va_list *ap, char *buf, t_flag flag)
{
	char	*temp;
	size_t	len;

	buf = numtohex(va_arg(*ap, unsigned int), 0, 1);
	buf = check_specialzero(buf, flag);
	len = ft_strlen(buf);
	if (flag.pcs > 0 && flag.pcs - 1 > len)
	{
		temp = ft_calloc(flag.pcs - len, sizeof(char));
		ft_memset(temp, '0', flag.pcs - len - 1);
		buf = ft_strjoin(temp, buf);
		len = ft_strlen(buf);
	}
	if (flag.width > len)
	{
		if (flag.minus == 1)
			buf = hex_case_minus(flag, buf, 1);
		else if (flag.zero == 1 && flag.pcs < 1)
			buf = hex_case_zero(flag, buf, 1);
		else
			buf = hex_case_onlywidth(flag, buf, 1);
	}
	else
		buf = hex_case_nowidth(flag, buf, 1);
	return (buf);
}

char	*print_hex_small(va_list *ap, char *buf, t_flag flag)
{
	char	*temp;
	size_t	len;

	buf = numtohex(va_arg(*ap, unsigned int), 0, 2);
	buf = check_specialzero(buf, flag);
	len = ft_strlen(buf);
	if (flag.pcs > 0 && flag.pcs - 1 > len)
	{
		temp = ft_calloc(flag.pcs - len, sizeof(char));
		ft_memset(temp, '0', flag.pcs - len - 1);
		buf = ft_strjoin(temp, buf);
		len = ft_strlen(buf);
	}
	if (flag.width > len)
	{
		if (flag.minus == 1)
			buf = hex_case_minus(flag, buf, 2);
		else if (flag.zero == 1 && flag.pcs < 1)
			buf = hex_case_zero(flag, buf, 2);
		else
			buf = hex_case_onlywidth(flag, buf, 2);
	}
	else
		buf = hex_case_nowidth(flag, buf, 2);
	return (buf);
}

char	*print_percent(char *buf, t_flag flag)
{
	if (flag.width > 1)
	{
		buf = (char *)malloc(flag.width * sizeof(char));
		if (!buf)
			return (NULL);
		if (flag.minus == 1)
		{
			ft_memset(buf, ' ', sizeof(buf));
			buf[0] = '%';
		}
		else if (flag.zero == 1)
		{
			ft_memset(buf, '0', sizeof(buf));
			buf[flag.width - 1] = '%';
		}
	}
	else
		buf = ft_strdup("%");
	return (buf);
}
