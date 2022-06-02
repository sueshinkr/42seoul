/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:34:25 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/02 13:36:18 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	void	*result;

	result = ptr;
	while (size-- > 0)
		*(unsigned char *)ptr++ = value;
	return (result);
}

char	*ft_strchr(const char *str, int c)
{
	while (1)
	{
		if (*str == (char)c)
			return ((char *)str);
		else if (!*str)
			return (NULL);
		str++;
	}
}

void	final_print(char *buf, int *count)
{
	write(1, buf, ft_strlen(buf));
	*count += ft_strlen(buf);
	free(buf);
}
