/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/07 13:04:40 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{	
	int	fd;
	int	i;
	char	*temp;

/*
	fd = open("nl", O_RDONLY);
	i = 0;
	
	
	
	while (temp =  get_next_line(fd))
	{	
		printf("%d : %s\n", i++, temp);
		printf("----------------end----------\n");
		free(temp);
	}
	
	//printf("%d : %s:::\n", i++, temp);
	//free(temp);
	close(fd);
	return (0);
*/
	char	n[10];
	read(0, n, 10);
	printf("%s\n", n);
	write(1, n, 10);
}
