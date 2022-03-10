/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:29:18 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 14:11:43 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str);

size_t	ft_strlcpy(char *restrict dest, char *restrict src, size_t size)
{
	if (size == 0)
		return (ft_strlen(src));
	while (size-- > 1)
		*dest++ = *src++;
	*dest = '\0';
	return (ft_strlen(src));
}
