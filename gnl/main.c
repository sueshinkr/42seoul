/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/01 13:48:23 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{	
	int	fd;
	int	i;
	char	*temp;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	
	temp =  get_next_line(fd);
	while (temp)
	{	
		printf("%d : %s:::\n", i++, temp);
		free(temp);
		temp =  get_next_line(fd);
	}
	free(temp);
	return (0);
}
