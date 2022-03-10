/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:49:50 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 16:37:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t size)
{
	void	*start;

	start = dst;
	if (!dst && !src)
		return (0);
	while (size-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (start);
}
