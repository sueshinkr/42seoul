/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/26 15:59:51 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	func(unsigned int i, char *c)
{
	*c += i;
}

int	main()
{
	void	*temp;
	char	*temp2;

	temp = (void *)0;
	memmove(temp, ((void *)0), 3);
	temp2 = ft_memcpy(((void *)0), ((void *)0), 3);
	printf("%s\n", temp);
	printf("%s\n", temp2);
}
