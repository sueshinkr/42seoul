/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:15:31 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/17 03:05:22 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t size)
{
	while (size-- > 0)
	{
		if (*(unsigned char *)str == (unsigned char)value)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
