/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:41:19 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/04 16:02:04 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal(va_list *ap, char *buf, t_flag flag)
{
	int		sign;
	char	*temp;

	sign = 1;
	buf = ft_itoa(va_arg(*ap, int), &sign);
	buf = check_specialzero(buf, flag);
	if (flag.pcs > 0 && flag.pcs - 1 > ft_strlen(buf))
	{
		temp = ft_calloc(flag.pcs - ft_strlen(buf), sizeof(char));
		ft_memset(temp, '0', flag.pcs - ft_strlen(buf) - 1);
		buf = ft_strjoin(temp, buf);
	}
	if ((sign == 1 && flag.width > ft_strlen(buf))
		|| (sign == -1 && flag.width > ft_strlen(buf) + 1))
	{
		if (flag.minus == 1)
			buf = number_case_minus(flag, buf, sign);
		else if (flag.zero == 1 && flag.pcs == 0)
			buf = number_case_zero(flag, buf, sign);
		else
			buf = number_case_onlywidth(flag, buf, sign);
	}
	else
		buf = number_case_nowidth(flag, buf, sign);
	return (buf);
}

char	*print_integer(va_list *ap, char *buf, t_flag flag)
{
	int		sign;
	char	*temp;

	sign = 1;
	buf = ft_itoa(va_arg(*ap, int), &sign);
	buf = check_specialzero(buf, flag);
	if (flag.pcs > 0 && flag.pcs - 1 > ft_strlen(buf))
	{
		temp = ft_calloc(flag.pcs - ft_strlen(buf), sizeof(char));
		ft_memset(temp, '0', flag.pcs - ft_strlen(buf) - 1);
		buf = ft_strjoin(temp, buf);
	}
	if ((sign == 1 && flag.width > ft_strlen(buf))
		|| (sign == -1 && flag.width > ft_strlen(buf) + 1))
	{
		if (flag.minus == 1)
			buf = number_case_minus(flag, buf, sign);
		else if (flag.zero == 1 && flag.pcs == 0)
			buf = number_case_zero(flag, buf, sign);
		else
			buf = number_case_onlywidth(flag, buf, sign);
	}
	else
		buf = number_case_nowidth(flag, buf, sign);
	return (buf);
}

char	*print_unsigned_decimal(va_list *ap, char *buf, t_flag flag)
{
	char	*temp;
	size_t	len;

	buf = ft_uitoa(va_arg(*ap, unsigned int));
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
			buf = number_case_minus(flag, buf, 0);
		else if (flag.zero == 1 && flag.pcs == 0)
			buf = number_case_zero(flag, buf, 0);
		else
			buf = number_case_onlywidth(flag, buf, 0);
	}
	else
		buf = number_case_nowidth(flag, buf, 0);
	return (buf);
}
