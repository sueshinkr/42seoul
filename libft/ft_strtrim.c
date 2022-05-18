/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/29 16:24:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static int	set_start(char const *str, char const *set)
{
	int	i;
	int	start_i;

	i = 0;
	start_i = 0;
	while (set[i])
	{
		if (str[start_i] == set[i])
		{
			start_i++;
			i = 0;
		}
		else
			i++;
	}
	return (start_i);
}

static int	set_end(char const *str, char const *set)
{
	int	i;
	int	end_i;

	i = 0;
	end_i = ft_strlen(str) - 1;
	while (set[i])
	{
		if (str[end_i] == set[i] && end_i != 0)
		{
			end_i--;
			i = 0;
		}
		else
			i++;
	}
	return (end_i);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trimstr;
	char	*result;
	int		start_i;
	int		end_i;

	start_i = set_start(str, set);
	end_i = set_end(str, set);
	if (start_i > end_i)
		return (ft_strdup(""));
	trimstr = (char *)malloc((end_i - start_i + 2) * sizeof(char));
	if (!trimstr)
		return (NULL);
	result = trimstr;
	while (end_i - start_i + 1 > 0)
		*trimstr++ = *(str + start_i++);
	*trimstr = 0;
	return (result);
}
*/

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trimstr;
	char	*result;
	char	*start;
	char	*end;

	start = ft_strchr(str, (int)set);
	end = ft_strrchr(str, (int)set);
	if (start > end)
		return (ft_strdup(""));
	trimstr = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trimstr)
		return (NULL);
	result = trimstr;
	while (end - start + 1 > 0)
		*trimstr++ = *start++;
	*trimstr = 0;
	return (result);
}
