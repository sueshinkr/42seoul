/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:09:53 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 16:37:22 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	dest_i;
	size_t	src_i;
	size_t	src_len;

	dest_i = 0;
	src_i = 0;
	src_len = ft_strlen(src);
	while (*dest)
	{
		dest++;
		dest_i++;
	}
	if (dest_i > size)
		return (size + src_len);
	while (*src && dest_i + src_i + 1 < size)
	{
		*dest++ = *src++;
		src_i++;
	}
	*dest = 0;
	return (dest_i + src_len);
}
