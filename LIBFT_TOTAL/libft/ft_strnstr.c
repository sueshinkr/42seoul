/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:48:29 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/25 17:44:39 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	count;
	size_t	little_len;

	count = 0;
	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	while (*big && size-- > 0)
	{
		if (*big == little[count])
			count++;
		else
		{
			big -= count;
			count = 0;
		}
		if (count == little_len)
			return ((char *)big - count + 1);
		big++;
	}
	return (NULL);
}
