/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:33:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 18:47:14 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dst, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	i = 0;
	while ((dst_char[i] || src_char[i]) && i < size)
	{
		if (dst_char[i] != src_char[i])
			return (dst_char[i] - src_char[i]);
		i++;
	}
	return (0);
}
