/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/24 19:36:44 by sueshin          ###   ########.fr       */
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

static void	free_cmd(t_arg *arg)
{
	int	idx1;
	int	idx2;

	idx1 = -1;
	while(++idx1 < arg->cmd_num)
	{
		idx2 = -1;
		while (arg->cmd[idx1]->cmd_str[++idx2])
			free(arg->cmd[idx1]->cmd_str[idx2]);
		free(arg->cmd[idx1]->cmd_str);
		if (arg->cmd[idx1]->cmd_path)
			free(arg->cmd[idx1]->cmd_path);
		free(arg->cmd[idx1]);
	}
	free(arg->cmd);
}

static void	free_path(t_arg *arg)
{
	int	idx;

	idx = -1;
	while (arg->path[++idx])
		free(arg->path[idx]);
	free(arg->path);
}

void	print_error(int num, t_arg *arg)
{
	if (num == 1)
	{
		ft_printf("ARG Error\n");
		exit(1);
	}
	else if (num == 2)
	{
		ft_printf("File Error\n");
		free_arg(arg);
		exit(1);
	}
	else if (num == 3)
	{
		ft_printf("Not valid CMD Error\n");
		free_cmd(arg);
		free_path(arg);
		free(arg);
		exit(1);
	}
	else if (num == 4)
	{
		ft_printf("execve Error\n");
		free_cmd(arg);
		free_path(arg);
		free(arg);
	}
}

static t_arg	*init_arg(int argc, char **envp)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(1);
	arg->cmd = malloc(sizeof(t_cmd *) * (argc - 3));
	arg->cmd_num = 0;
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
		if (!arg->cmd[idx]->cmd_path)
			return ;
		if (execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, arg->envp) == -1)
			print_error(4, arg);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	close(fd[0]);
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
	idx = -1;
	while (++idx < argc - 4)
		pipe_in(arg, argc, argv, idx);
	open_outfile(argv[argc - 1], arg);
	if (!arg->cmd[idx]->cmd_path)
	{
		free_cmd(arg);
		free_path(arg);
		free(arg);
		exit(1);
	}
	if (execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, envp) == -1)
		print_error(4, arg);

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
