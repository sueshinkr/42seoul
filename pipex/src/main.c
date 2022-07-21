/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/21 15:32:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd[2]; 
	pid_t	pid;
	int		x;
	char	*str;

	pipe(fd); // fd[0] : read, fd[1] : write
	pid = fork();

	if (pid == 0) // child
	{
		close(fd[0]);
		dup2(fd[1], 1);
		x = 1;
		write(1, "hello\n", 6);
		//ft_printf("child : %d, x : %d\n", getpid(), x);
	}
	else // parent
	{
		close(fd[1]);
		dup2(fd[0], 0);
		x = 2;
		str = get_next_line(0);
		ft_printf("str : %s", str);
		ft_printf("parent : %d, x : %d\n", getpid(), x);
	}
	//ft_printf("x : %d ::::\n", x);
}

/*
infile outfile