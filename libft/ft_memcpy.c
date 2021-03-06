/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:49:50 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/30 12:20:17 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	void	*result;

	result = dst;
	if (dst == src)
		return (result);
	while (size-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (result);
}
