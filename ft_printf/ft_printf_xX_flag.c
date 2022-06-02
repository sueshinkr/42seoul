/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:35 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/02 13:37:13 by sueshin          ###   ########.fr       */
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

char	*hex_case_minus(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[2] == 1 && ft_strncmp(buf, "0", sizeof(buf)))
		buf = hex_case_sharp(buf, bigorsmall);
	if (flag[6] > ft_strlen(buf))
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		buf = ft_strjoin(buf, temp);
	}
	return (buf);
}

char	*hex_case_onlywidth(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[2] == 1)
		buf = hex_case_sharp(buf, bigorsmall);
	temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
	ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
	buf = ft_strjoin(temp, buf);
	return (buf);
}

char	*hex_case_zero(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[2] == 1)
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) - 1, sizeof(char));
		ft_memset(temp, '0', flag[6] - ft_strlen(buf) - 2);
		buf = ft_strjoin(temp, buf);
		buf = hex_case_sharp(buf, bigorsmall);
	}
	else
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char));
		ft_memset(temp, '0', flag[6] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	return (buf);
}

char	*hex_case_nowidth(size_t *flag, char *buf, int bigorsmall)
{
	if (flag[2] == 1 && ft_strncmp(buf, "0", sizeof(buf)))
		buf = hex_case_sharp(buf, bigorsmall);
	return (buf);
}
