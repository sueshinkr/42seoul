/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:34:25 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/03 19:29:20 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	size_t	idx;

	idx = 0;
	while (size-- > 0)
		*(unsigned char *)(ptr + idx++) = value;
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, nmemb * size);
	return (temp);
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

char	*check_specialzero(char *buf, size_t *flag)
{
	if (flag[5] > 0 && ft_strncmp(buf, "0", 1) == 0)
	{
		free(buf);
		buf = ft_strdup("");
	}
	return (buf);
}

void	buf_print(char *buf, int *count)
{
	write(1, buf, ft_strlen(buf));
	*count += ft_strlen(buf);
	free(buf);
}
