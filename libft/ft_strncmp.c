/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:14:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/12 00:58:20 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *dst, const char *src, size_t size)
{
	size_t			i;
	unsigned char	*dst_ui;
	unsigned char	*src_ui;

	dst_ui = (unsigned char *)dst;
	src_ui = (unsigned char *)src;
	i = 0;
	while ((dst_ui[i] || src_ui[i]) && i < size)
	{
		if (dst_ui[i] > src_ui[i])
			return (1);
		else if (dst_ui[i] < src_ui[i])
			return (-1);
		i++;
	}
	return (0);
}
