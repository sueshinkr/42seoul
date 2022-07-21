/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:29:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/21 23:58:53 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (src_len);
}

static void	free_str(char **splitstr)
{
	while (!*splitstr)
		free(*splitstr++);
	free(splitstr);
}

static int	word_count(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			count++;
			while (*str != c && *str)
				str++;
		}
	}
	return (count);
}

static char	**plus_word(char const *str, char c, char **splitstr)
{
	int	len;

	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			len = 0;
			while (*str != c && *str)
			{
				str++;
				len++;
			}
			*splitstr = (char *)malloc((len + 1) * sizeof(char));
			if (!*splitstr)
			{
				free_str(splitstr);
				return (NULL);
			}
			ft_strlcpy((char *)*splitstr++, (char *)str - len, len + 1);
		}
	}
	return (splitstr);
}

char	**ft_split(char const *str, char const *str2, char c)
{
	char	**splitstr;
	char	**laststr;

	splitstr = (char **)malloc((word_count(str, c) + 2) * sizeof(char *));
	if (!splitstr)
		return (NULL);
	laststr = plus_word(str, c, splitstr);
	if (!laststr)
		return (NULL);
	*laststr = (char *)malloc((ft_strlen(str2) + 1) * sizeof(char));
	ft_strlcpy((char *)*laststr++, (char *)str2, ft_strlen(str2) + 1);
	*laststr = 0;
	return (splitstr);
}

