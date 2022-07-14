/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:56:58 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/04 23:40:40 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dop(const char **str)
{
	int	dop;

	dop = 0;
	(*str)++;
	if (*(*str) >= '0' && *(*str) <= '9')
	{
		while (*(*str) >= '0' && *(*str) <= '9')
		{
			dop = dop * 10 + *(*str) - '0';
			(*str)++;
		}
		(*str)--;
		return (dop + 1);
	}
	(*str)--;
	return (1);
}

static int	width(const char **str)
{
	int	width;

	width = 0;
	{
		while (*(*str) >= '0' && *(*str) <= '9')
		{
			width = width * 10 + *(*str) - '0';
			(*str)++;
		}
		(*str)--;
	}
	return (width);
}

void	select_flag(const char **str, va_list *ap, int *count)
{
	t_flag	flag;

	ft_memset(&flag, 0, sizeof(t_flag));
	while (!ft_strchr("cspdiuxX%%", *(*str)))
	{
		if (*(*str) == '-')
			flag.minus = 1;
		else if (*(*str) == '0')
			flag.zero = 1;
		else if (*(*str) == '#')
			flag.sharp = 1;
		else if (*(*str) == ' ')
			flag.space = 1;
		else if (*(*str) == '+')
			flag.plus = 1;
		else if (*(*str) == '.')
			flag.pcs = dop(str);
		else
			flag.width = width(str);
		(*str)++;
	}
	select_format(str, ap, count, flag);
}

void	select_format(const char **str, va_list *ap, int *count, t_flag flag)
{
	char	*buf;

	buf = NULL;
	if (*(*str) == 'c')
	{
		print_char(ap, count, flag);
		return ;
	}
	else if (*(*str) == 's')
		buf = print_str(ap, buf, flag);
	else if (*(*str) == 'p')
		buf = print_pointer(ap, buf, flag);
	else if (*(*str) == 'd')
		buf = print_decimal(ap, buf, flag);
	else if (*(*str) == 'i')
		buf = print_integer(ap, buf, flag);
	else if (*(*str) == 'u')
		buf = print_unsigned_decimal(ap, buf, flag);
	else if (*(*str) == 'x')
		buf = print_hex_small(ap, buf, flag);
	else if (*(*str) == 'X')
		buf = print_hex_big(ap, buf, flag);
	else if (*(*str) == '%')
		buf = print_percent(buf, flag);
	buf_print(buf, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '"')
			str++;
		else if (*str == '%')
		{
			str++;
			select_flag(&str, &ap, &count);
			str++;
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
