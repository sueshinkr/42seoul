/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:41:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/12 14:08:59 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*joinstr;
	int		joinstr_len;
	int		i;

	i = 0;
	joinstr_len = ft_strlen(str1) + ft_strlen(str2);
	joinstr = (char *)malloc(joinstr_len * sizeof(char) + 1);
	if (!joinstr)
		return (NULL);
	while (i < joinstr_len)
	{
		if (*str1)
			joinstr[i] = *str1++;
		else if (*str2)
			joinstr[i] = *str2++;
		i++;
	}
	joinstr[i] = 0;
	return (joinstr);
}
