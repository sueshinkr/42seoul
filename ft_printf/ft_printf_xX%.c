/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:36:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/03 17:50:44 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_hex_big(va_list *ap, char *buf, size_t *flag)
{
	char	*temp;
	size_t	len;

	buf = numtohex(va_arg(*ap, unsigned int), 1);
	buf = check_specialzero(buf, flag);
	len = ft_strlen(buf);
	if (flag[5] > 0 && flag[5] - 1 > len)
	{
		temp = ft_calloc(flag[5] - len, sizeof(char));
		ft_memset(temp, '0', flag[5] - len - 1);
		buf = ft_strjoin(temp, buf);
		len = ft_strlen(buf);
	}
	if (flag[6] > len)
	{
		if (flag[0] == 1)
			buf = hex_case_minus(flag, buf, 1);
		else if (flag[1] == 1 && flag[5] < 1)
			buf = hex_case_zero(flag, buf, 1);
		else
			buf = hex_case_onlywidth(flag, buf, 1);
	}
	else
		buf = hex_case_nowidth(flag, buf, 1);
	return (buf);
}

char	*print_hex_small(va_list *ap, char *buf, size_t *flag)
{
	char	*temp;
	size_t	len;

	buf = numtohex(va_arg(*ap, unsigned int), 2);
	buf = check_specialzero(buf, flag);
	len = ft_strlen(buf);
	if (flag[5] > 0 && flag[5] - 1 > len)
	{
		temp = ft_calloc(flag[5] - len, sizeof(char));
		ft_memset(temp, '0', flag[5] - len - 1);
		buf = ft_strjoin(temp, buf);
		len = ft_strlen(buf);
	}
	if (flag[6] > len)
	{
		if (flag[0] == 1)
			buf = hex_case_minus(flag, buf, 2);
		else if (flag[1] == 1 && flag[5] < 1)
			buf = hex_case_zero(flag, buf, 2);
		else
			buf = hex_case_onlywidth(flag, buf, 2);
	}
	else
		buf = hex_case_nowidth(flag, buf, 2);
	return (buf);
}

char	*print_percent(char *buf, size_t *flag)
{
	if (flag[6] > 1)
	{
		buf = (char *)malloc(flag[6] * sizeof(char));
		if (!buf)
			return (NULL);
		if (flag[0] == 1)
		{
			ft_memset(buf, ' ', sizeof(buf));
			buf[0] = '%';
		}
		else if (flag[1] == 1)
		{
			ft_memset(buf, '0', sizeof(buf));
			buf[flag[6] - 1] = '%';
		}
	}
	else
		buf = ft_strdup("%");
	return (buf);
}
