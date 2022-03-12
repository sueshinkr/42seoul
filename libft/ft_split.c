/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:03:55 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/12 15:18:28 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	plus_word(char const *str, char c, char **splitstr)
{
	int	len;
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			len = 0;
			while (*str != c && *str)
			{
				len++;
				str++;
			}
			splitstr[i] = (char *)malloc((len + 1) * sizeof(char));
			ft_strlcpy((char *restrict)splitstr[i], (char *)str - len, len + 1);
			i++;
		}
	}
	splitstr[i] = 0;
}

char	**ft_split(char const *str, char c)
{
	char	**splitstr;

	splitstr = (char **)malloc((word_count(str, c) + 1) * sizeof(char *));
	if (!splitstr)
		return (NULL);
	plus_word(str, c, splitstr);
	return (splitstr);
}
