/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/24 21:59:19 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	pipe_in(t_arg *arg, int idx)
{
	int		fd[2];
	int		status;
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
		waitpid(pid, &status, WNOHANG);
	/*
		if (WIFSIGNALED(status))
		{
			//ft_printf("Exit Signal : %d\n", WTERMSIG(status));
			arg->exit_code = WTERMSIG(status);
		}
	*/
		close(fd[0]);
	}

}

void	pipe_in_last(t_arg *arg, char **argv, int argc, int idx)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(open_outfile(argv[argc - 1], arg), 1);
		if (!arg->cmd[idx]->cmd_path)
		{
			free_cmd(arg);
			free_path(arg);
			free(arg);
			exit(127);
		}
		if (execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, arg->envp) == -1)
			print_error(4, arg);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		close(fd[1]);
		close(fd[0]);
		
	/*
		if (WIFSIGNALED(status))
		{
			//ft_printf("Exit Signal : %d\n", WTERMSIG(status));
			arg->exit_code = WTERMSIG(status);
		}
	*/
	}

}
