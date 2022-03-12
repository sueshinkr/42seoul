/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:22:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/12 14:09:03 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (str[end_i] == set[i])
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
	int		i;
	int		start_i;
	int		end_i;

	trimstr = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!trimstr)
		return (NULL);
	start_i = set_start(str, set);
	end_i = set_end(str, set);
	i = 0;
	while (i < end_i - start_i + 1)
	{
		trimstr[i] = str[start_i + i];
		i++;
	}
	trimstr[i] = 0;
	return (trimstr);
}
