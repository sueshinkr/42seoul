/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:22:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/09 19:49:34 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	*ft_memset(void *ptr, int value, size_t size)
{
	void	*start;

	start = ptr;
	while (size-- > 0)
	{
		*(unsigned char *)ptr = value;
		ptr++;
	}
	return (start);
}
