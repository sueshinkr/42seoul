/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/12 20:33:02 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{	
	int		fd;
	char	*temp;

	fd = open("./empty", O_RDWR);

	temp = get_next_line(1000);
	printf("1:::::%s", temp);
	free(temp);

	temp = get_next_line(-1);
	printf("2:::::%s", temp);
	free(temp);

	temp = get_next_line(fd);
	printf("3:::::%s", temp);
	free(temp);
	

	/*
	fd[0] = open("test1.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);


	temp = get_next_line(fd[0]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[1]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[2]);
	printf(":::::%s", temp);
	free(temp);


	temp = get_next_line(fd[0]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[2]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[1]);
	printf(":::::%s", temp);
	free(temp);

	temp = get_next_line(fd[2]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[0]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[1]);
	printf(":::::%s", temp);
	free(temp);
	
	
	temp = get_next_line(fd[1]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[0]);
	printf(":::::%s", temp);
	free(temp);
	temp = get_next_line(fd[2]);
	printf(":::::%s", temp);
	free(temp);
	
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
	close(fd);
	return (0);
}
