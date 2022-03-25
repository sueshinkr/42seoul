/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:14:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/25 17:44:27 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t			i;
	unsigned char	*str1_u;
	unsigned char	*str2_u;

	str1_u = (unsigned char *)str1;
	str2_u = (unsigned char *)str2;
	i = 0;
	while ((str1_u[i] || str2_u[i]) && i < size)
	{
		if (str1_u[i] != str2_u[i])
			return (str1_u[i] - str2_u[i]);
		i++;
	}
	return (0);
}
