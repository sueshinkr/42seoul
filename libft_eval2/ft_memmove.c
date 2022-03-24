/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:26:57 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/16 01:42:17 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	void	*start;

	start = dst;
	if (dst < src)
	{
		while (size-- > 0)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	else
	{
		while (size-- > 0)
			*(unsigned char *)(dst + size) = *(unsigned char *)(src + size);
	}	
	return (start);
}
