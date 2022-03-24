/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:33:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/17 13:10:22 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	size_t			i;
	unsigned char	*str1_char;
	unsigned char	*str2_char;

	str1_char = (unsigned char *)str1;
	str2_char = (unsigned char *)str2;
	i = 0;
	while (i < size)
	{
		if (str1_char[i] != str2_char[i])
			return (str1_char[i] - str2_char[i]);
		i++;
	}
	return (0);
}
