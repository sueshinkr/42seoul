/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:41:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/06/02 12:38:44 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*substr;
	char	*result;
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
	result = substr;
	while (*(str + start) && len-- > 0)
		*substr++ = *(str + start++);
	*substr = 0;
	free(str);
	return (result);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	char	*joinstr;
	int		joinstr_len;
	int		idx1;
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

	if (!src)
		return (NULL);
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
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
