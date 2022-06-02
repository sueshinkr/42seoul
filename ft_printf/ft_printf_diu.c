/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:41:19 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/02 15:15:51 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal(va_list *ap, char *buf, size_t *flag)
{
	int		minus;
	char	*temp;

	minus = 0;
	buf = ft_itoa(va_arg(*ap, int), &minus);
	buf = check_spetialzero(buf, flag);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf))
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if ((minus == 0 && flag[6] > ft_strlen(buf))
		|| (minus == 1 && flag[6] > ft_strlen(buf) + 1))
	{
		if (flag[0] == 1)
			buf = number_case_minus(flag, buf, minus);
		else if (flag[1] == 1 && flag[5] == 0)
			buf = number_case_zero(flag, buf, minus);
		else
			buf = number_case_onlywidth(flag, buf, minus);
	}
	else
		buf = number_case_nowidth(flag, buf, minus);
	return (buf);
}

char	*print_integer(va_list *ap, char *buf, size_t *flag)
{
	int		minus;
	char	*temp;

	minus = 0;
	buf = ft_itoa(va_arg(*ap, int), &minus);
	buf = check_spetialzero(buf, flag);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf))
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if ((minus == 0 && flag[6] > ft_strlen(buf))
		|| (minus == 1 && flag[6] > ft_strlen(buf) + 1))
	{
		if (flag[0] == 1)
			buf = number_case_minus(flag, buf, minus);
		else if (flag[1] == 1 && flag[5] == 0)
			buf = number_case_zero(flag, buf, minus);
		else
			buf = number_case_onlywidth(flag, buf, minus);
	}
	else
		buf = number_case_nowidth(flag, buf, minus);
	return (buf);
}

char	*print_unsigned_decimal(va_list *ap, char *buf, size_t *flag)
{
	char	*temp;

	buf = ft_uitoa(va_arg(*ap, unsigned int));
	buf = check_spetialzero(buf, flag);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf))
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf))
	{
		if (flag[0] == 1)
			buf = number_case_minus(flag, buf, 0);
		else if (flag[1] == 1 && flag[5] == 0)
			buf = number_case_zero(flag, buf, 0);
		else
			buf = number_case_onlywidth(flag, buf, 0);
	}
	else
		buf = number_case_nowidth(flag, buf, 0);
	return (buf);
}
