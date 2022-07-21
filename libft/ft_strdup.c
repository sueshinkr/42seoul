/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:34:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/21 22:16:45 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*result;

	printf("!!!!!!!!!!!\n");
	fflush(stdout);
	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
	{
		printf("NULL\n");
		return (NULL);
	}
	printf("not NULL\n");
	result = str;
	while (*src)
		*str++ = *src++;
	*str = 0;
	return (result);
}
