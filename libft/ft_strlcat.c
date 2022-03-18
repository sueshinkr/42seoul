/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:09:53 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/16 20:47:17 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_i;
	size_t	src_len;
	size_t	dst_len;

	src_i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > size)
		return (size + src_len);
	while (*src && dst_len + src_i + 1 < size)
	{
		*(dst + dst_len + src_i) = *src++;
		src_i++;
	}
	*(dst + dst_len + src_i) = 0;
	return (dst_len + src_len);
}
