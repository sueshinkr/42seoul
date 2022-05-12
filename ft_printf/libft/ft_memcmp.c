/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:33:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/26 14:48:52 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*str1_char;
	unsigned char	*str2_char;

	str1_char = (unsigned char *)str1;
	str2_char = (unsigned char *)str2;
	while (size-- > 0)
	{
		if (*str1_char != *str2_char)
			return (*str1_char - *str2_char);
		str1_char++;
		str2_char++;
	}
	return (0);
}
