/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/23 15:50:43 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_arg(t_arg *arg)
{
	int	idx;

	idx = -1;
/*
	while (arg->cmd[idx])
	{
		free(arg->cmd[idx]->cmd_str);
		free(arg->cmd[idx]->cmd_path);
		free(arg->cmd[idx]);
	}
*/
	//free(arg->path);
	free(arg->cmd);
	free(arg);
}

void	print_error(int num, t_arg *arg)
{
	if (num == 1)
	{
		ft_printf("ARG Error\n");
		exit(1);
	}
	if (num == 2)
	{
		ft_printf("File Error\n");
		free_arg(arg);
		exit(1);
	}
	if (num == 3)
	{
		ft_printf("Not valid cmdand Error\n");
		exit(1);
	}
}

static t_arg	*init_arg(int argc, char **envp)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(1);
	arg->cmd = malloc(sizeof(t_cmd *) * (argc - 3));
	arg->envp = envp;
	return (arg);
}

void	pipe_in(t_arg *arg, int argc, char **argv, int idx)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, arg->envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;
	int		fd[2]; 
	int		idx;

	if (argc < 5)
		print_error(1, arg);
	arg = init_arg(argc, envp);
	read_arg(argc - 3, argv, envp, arg);
	if (pipe(fd) == -1)  // fd[0] : read, fd[1] : write
		exit(1);
	idx = -1;
	while (++idx < argc - 4)
		pipe_in(arg, argc, argv, idx);
	open_outfile(argv[argc - 1], arg);
	execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, envp);

/*
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
*/

}

/*
Wait함수 적용, 파이프 여러개일때 어떻게 해야할지 생각하기
*/
