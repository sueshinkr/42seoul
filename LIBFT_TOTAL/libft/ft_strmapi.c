/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:06:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/20 21:59:38 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	int		i;
	char	*func_str;

	i = 0;
	func_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!func_str)
		return (NULL);
	while (str[i])
	{
		func_str[i] = func(i, str[i]);
		i++;
	}
	func_str[i] = 0;
	return (func_str);
}
