/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:41:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/23 22:04:28 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
