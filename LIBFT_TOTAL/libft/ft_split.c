/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:03:55 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/25 16:50:29 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(char **splitstr)
{
	int	i;

	i = 0;
	while (!splitstr[i])
		free(splitstr[i++]);
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

static int	plus_word(char const *str, char c, char **splitstr, int i)
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
			splitstr[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!splitstr[i])
			{
				free_str(splitstr);
				return (-1);
			}
			ft_strlcpy((char *)splitstr[i++], (char *)str - len, len + 1);
		}
	}
	splitstr[i] = 0;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**splitstr;

	splitstr = (char **)malloc((word_count(str, c) + 1) * sizeof(char *));
	if (!splitstr)
		return (NULL);
	if ((plus_word(str, c, splitstr, 0)) == -1)
		return (NULL);
	return (splitstr);
}
