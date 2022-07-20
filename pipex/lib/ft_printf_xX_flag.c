/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:35 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/04 14:56:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex_case_sharp(char *buf, int bigorsmall)
{
	if (bigorsmall == 1)
		buf = ft_strjoin(ft_strdup("0X"), buf);
	else
		buf = ft_strjoin(ft_strdup("0x"), buf);
	return (buf);
}

char	*hex_case_minus(t_flag flag, char *buf, int bigorsmall)
{
	char	*temp;
	size_t	len;

	if (flag.sharp == 1 && ft_strncmp(buf, "0", sizeof(buf)))
		buf = hex_case_sharp(buf, bigorsmall);
	len = ft_strlen(buf);
	if (flag.width > len)
	{
		temp = ft_calloc(flag.width - len + 1, sizeof(char));
		ft_memset(temp, ' ', flag.width - len);
		buf = ft_strjoin(buf, temp);
	}
	return (buf);
}

char	*hex_case_onlywidth(t_flag flag, char *buf, int bigorsmall)
{
	char	*temp;
	size_t	len;

	if (flag.sharp == 1)
		buf = hex_case_sharp(buf, bigorsmall);
	len = ft_strlen(buf);
	temp = ft_calloc(flag.width - len + 1, sizeof(char));
	ft_memset(temp, ' ', flag.width - len);
	buf = ft_strjoin(temp, buf);
	return (buf);
}

char	*hex_case_zero(t_flag flag, char *buf, int bigorsmall)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(buf);
	if (flag.sharp == 1)
	{
		temp = ft_calloc(flag.width - len - 1, sizeof(char));
		ft_memset(temp, '0', flag.width - len - 2);
		buf = ft_strjoin(temp, buf);
		buf = hex_case_sharp(buf, bigorsmall);
	}
	else
	{
		temp = ft_calloc(flag.width - len + 1, sizeof(char));
		ft_memset(temp, '0', flag.width - len);
		buf = ft_strjoin(temp, buf);
	}
	return (buf);
}

char	*hex_case_nowidth(t_flag flag, char *buf, int bigorsmall)
{
	if (flag.sharp == 1 && ft_strncmp(buf, "0", sizeof(buf)))
		buf = hex_case_sharp(buf, bigorsmall);
	return (buf);
}
