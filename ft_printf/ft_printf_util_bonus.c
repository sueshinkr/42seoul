/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:41:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/24 20:20:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	char	*joinstr;
	int		joinstr_len;
	int 	idx1;
	int		idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = ft_strlen(str1) + ft_strlen(str2);
	joinstr = (char *)malloc((joinstr_len + 1) * sizeof(char));
	result = joinstr;
	if (!joinstr)
		return (NULL);
	while (joinstr_len-- > 0)
	{
		if (*(str1 + idx1))
			*joinstr = *(str1 + idx1++);
		else if (*(str2 + idx2))
			*joinstr = *(str2 + idx2++);
		joinstr++;
	}
	*joinstr = 0;
	free(str1);
	free(str2);
	return (result);
}

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned char	*str1_unchar;
	unsigned char	*str2_unchar;

	str1_unchar = (unsigned char *)str1;
	str2_unchar = (unsigned char *)str2;
	while ((*str1_unchar || *str2_unchar) && size-- > 0)
	{
		if (*str1_unchar != *str2_unchar)
			return (*str1_unchar - *str2_unchar);
		str1_unchar++;
		str2_unchar++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*result;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	result = str;
	while (*src)
		*str++ = *src++;
	*str = 0;
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

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

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long long	nb;
	
	nb = n;
	count = cal_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		nb = nb * -1;
	}
	if (n == 0)
		*str = '0';
	*(str + count) = 0;
	while (nb > 0)
	{
		*(str + --count) = nb % 10 | '0';
		nb /= 10;
	}
	return (str);
}


