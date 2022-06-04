/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:24:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/04 15:52:42 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*number_case_minus(t_flag flag, char *buf, int sign)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(buf);
	if (sign == -1)
		len++;
	temp = ft_calloc(flag.width - len + 1, sizeof(char));
	ft_memset(temp, ' ', flag.width - len);
	buf = ft_strjoin(buf, temp);
	if (sign == -1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag.space == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag.plus == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}

char	*number_case_zero(t_flag flag, char *buf, int sign)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(buf);
	if (sign == -1)
		len++;
	temp = ft_calloc(flag.width - len + 1, sizeof(char));
	ft_memset(temp, '0', flag.width - len);
	buf = ft_strjoin(temp, buf);
	if (sign == -1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag.space == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag.plus == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}

char	*number_case_onlywidth(t_flag flag, char *buf, int sign)
{
	char	*temp;
	size_t	len;

	if (sign == -1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag.space == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag.plus == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	len = ft_strlen(buf);
	temp = ft_calloc(flag.width - len + 1, sizeof(char));
	ft_memset(temp, ' ', flag.width - len);
	buf = ft_strjoin(temp, buf);
	return (buf);
}

char	*number_case_nowidth(t_flag flag, char *buf, int sign)
{
	if (sign == -1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag.space == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag.plus == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}
