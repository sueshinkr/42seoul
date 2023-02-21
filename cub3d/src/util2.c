/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:22:30 by taehyeok          #+#    #+#             */
/*   Updated: 2023/02/19 17:45:44 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	_word_count(char const *str, char c)
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

static int	plus__word(char const *str, char c, char **splitstr)
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
				return (-1);
			}
			ft_strlcpy((char *)*splitstr++, (char *)str - len, len + 1);
		}
	}
	*splitstr = 0;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**splitstr;

	splitstr = (char **)malloc((_word_count(str, c) + 1) * sizeof(char *));
	if (!splitstr)
		return (NULL);
	if ((plus__word(str, c, splitstr)) == -1)
		return (NULL);
	return (splitstr);
}
