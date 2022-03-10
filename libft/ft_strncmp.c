/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:14:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 18:46:21 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((dst[i] || src[i]) && i < size)
	{
		if (dst[i] > src[i])
			return (1);
		else if (dst[i] < src[i])
			return (-1);
		i++;
	}
	return (0);
}
