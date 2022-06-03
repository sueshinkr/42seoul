/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:41:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/03 17:13:43 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	idx;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	else if (len + start > str_len)
		substr = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	idx = 0;
	while (*(str + start) && len-- > 0)
		*(substr + idx++) = *(str + start++);
	*(substr + idx)= 0;
	free(str);
	return (substr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	joinstr = (char *)malloc(joinstr_len * sizeof(char));
	if (!joinstr)
		return (NULL);
	while (*(str1 + idx1))
	{
		*(joinstr + idx1) = *(str1 + idx1);
		idx1++;
	}
	while (*(str2 + idx2))
	{
		*(joinstr + idx1 + idx2) = *(str2 + idx2);
		idx2++;
	}
	*(joinstr + idx1 + idx2) = 0;
	free(str1);
	free(str2);
	return (joinstr);
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
	size_t	idx;

	if (!src)
		return (NULL);
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	idx = 0;
	while (*(src + idx))
	{
		*(str + idx) = *(src + idx);
		idx++;
	}
	*(str + idx) = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
