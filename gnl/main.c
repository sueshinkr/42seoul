/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/07 17:37:18 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{	
	int		fd[3];
	int		idx;
	int		num;
	char	*temp;

	fd[0] = open("test1.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);

	temp = get_next_line(fd[0]);
	printf("%s", temp);
	temp = get_next_line(fd[1]);
	printf("%s", temp);
	temp = get_next_line(fd[2]);
	printf("%s", temp);
	temp = get_next_line(fd[0]);
	printf("%s", temp);
	temp = get_next_line(fd[1]);
	printf("%s", temp);
	temp = get_next_line(fd[2]);
	printf("%s", temp);
	temp = get_next_line(fd[0]);
	printf("%s", temp);
	temp = get_next_line(fd[1]);
	printf("%s", temp);
	temp = get_next_line(fd[2]);
	printf("%s", temp);
	temp = get_next_line(fd[0]);
	printf("%s", temp);
	temp = get_next_line(fd[1]);
	printf("%s", temp);
	temp = get_next_line(fd[2]);
	printf("%s", temp);

	/*
	num = -1;
	while (num++ < 3)
	{
		idx = 0;
		while ((temp = get_next_line(fd[num])))
		{	
			printf("%d : %s\n", idx++, temp);
			printf("----------------end----------\n");
			free(temp);
		}
		close(fd[num]);
	}
	*/
	free(temp);
	return (0);
}
