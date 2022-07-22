/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 19:08:11 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(int num)
{
	if (num == 1)
	{
		ft_printf("ARG Error\n");
		exit(1);
	}
	if (num == 2)
	{
		ft_printf("File Error\n");
		exit(1);
	}
	if (num == 3)
	{
		ft_printf("Not valid cmdand Error\n");
		exit(1);
	}
}

static t_list	*init_list()
{
	t_list	*arg;

	arg = malloc(sizeof(t_list));
	if (!arg)
		exit(1);
	return (arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*arg;
	int		fd[2]; 
	pid_t	pid;
	int		x;
	char	*str;

	if (argc != 5)
		print_error(1);
	arg = init_list();
	read_arg(argv, envp, arg);
	if (pipe(fd) == -1)  // fd[0] : read, fd[1] : write
		exit(1);
	pid = fork();

	if (pid == 0) // child
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_printf("child - fd[0] : %d, fd[1] : %d\n", fd[0], fd[1]);
		execve(arg->path_cmd1, arg->cmd1, NULL);
	}
	else // parent
	{
		close(fd[1]);
		dup2(fd[0], 0);
		ft_printf("parent - fd[0] : %d, fd[1] : %d\n", fd[0], fd[1]);
		open_outfile(argv[4]);
		execve(arg->path_cmd2, arg->cmd2, NULL);
	}
}

/*
Wait함수 적용, 파이프 여러개일때 어떻게 해야할지 생각하기
*/
`