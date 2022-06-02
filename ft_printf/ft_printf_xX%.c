/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:36:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/02 13:53:14 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_big(va_list *ap, int *count, size_t *flag)
{
	char			*buf;
	char			*temp;

	buf = numtohex(va_arg(*ap, unsigned int), 1);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf))
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf))
	{
		if (flag[0] == 1)
			buf = hex_case_minus(flag, buf, 1);
		else if (flag[1] == 1)
			buf = hex_case_zero(flag, buf, 1);
		else
			buf = hex_case_onlywidth(flag, buf, 1);
	}
	else
		buf = hex_case_nowidth(flag, buf, 1);
	final_print(buf, count);
}

void	print_hex_small(va_list *ap, int *count, size_t *flag)
{
	char			*buf;
	char			*temp;

	buf = numtohex(va_arg(*ap, unsigned int), 2);
	if (flag[5] > 0 && flag[5] - 1 > ft_strlen(buf))
	{
		temp = (char *)calloc(--flag[5] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[5] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	if (flag[6] > ft_strlen(buf))
	{
		if (flag[0] == 1)
			buf = hex_case_minus(flag, buf, 2);
		else if (flag[1] == 1)
			buf = hex_case_zero(flag, buf, 2);
		else
			buf = hex_case_onlywidth(flag, buf, 2);
	}
	else
		buf = hex_case_nowidth(flag, buf, 2);
	final_print(buf, count);
}

void	print_percent(int *count, size_t *flag)
{
	char	*buf;

	if (flag[6] > 1)
	{
		buf = (char *)malloc(flag[6] * sizeof(char));
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
		final_print(buf, count);
	}
	else
	{
		write(1, "%%", 1);
		(*count)++;
	}
}
