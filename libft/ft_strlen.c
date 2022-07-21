/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:03:02 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/21 22:09:18 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	printf("::::::::::\n");
	printf("add : %p\n", str);
	while (*str)
	{
		len++;
		str++;
	}
	printf("len : %zu\n", len);
	return (len);
}
