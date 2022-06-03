/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:24:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/03 17:45:07 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*number_case_minus(size_t *flag, char *buf, int minus)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(buf);
	if (minus == 1)
		len++;
	temp = ft_calloc(flag[6] - len + 1, sizeof(char));
	ft_memset(temp, ' ', flag[6] - len);
	buf = ft_strjoin(buf, temp);
	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}

char	*number_case_zero(size_t *flag, char *buf, int minus)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(buf);
	if (minus == 1)
		len++;
	temp = ft_calloc(flag[6] - len + 1, sizeof(char));
	ft_memset(temp, '0', flag[6] - len);
	buf = ft_strjoin(temp, buf);
	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}

char	*number_case_onlywidth(size_t *flag, char *buf, int minus)
{
	char	*temp;
	size_t	len;

	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	len = ft_strlen(buf);
	temp = ft_calloc(flag[6] - len + 1, sizeof(char));
	ft_memset(temp, ' ', flag[6] - len);
	buf = ft_strjoin(temp, buf);
	return (buf);
}

char	*number_case_nowidth(size_t *flag, char *buf, int minus)
{
	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1)
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1)
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}
