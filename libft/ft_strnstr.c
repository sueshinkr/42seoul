/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:48:29 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 19:19:33 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *desert, const char *needle, size_t size)
{
	size_t	count;
	size_t	needle_len;

	count = 0;
	needle_len = ft_strlen(needle);
	if (!needle_len || !needle)
		return ((char *)desert);
	while (*desert && size-- > 0)
	{
		if (*desert == needle[count])
			count++;
		else
		{
			desert -= count;
			count = 0;
		}
		if (count == needle_len)
			return ((char *)desert - count + 1);
		desert++;
	}
	return (NULL);
}
