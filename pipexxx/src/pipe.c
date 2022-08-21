/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 14:44:30 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_in(t_arg *arg, int idx, int fdin)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		write(2, "PIPE Error\n", 11);
		exit(1);
	}
	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (fdin == 0)
			exit(1);
		if (!arg->cmd[idx]->cmd_path)
			exit(1);
		if (execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, arg->envp) == -1)
			print_error(4, arg);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, &status, WNOHANG);
	}
}

void	pipe_in_last(t_arg *arg, int idx)
{
	int		fd[2];
	int		status;
	pid_t	pid;
	int		temp = -1;

	if (pipe(fd) == -1)
	{
		write(2, "PIPE Error\n", 11);
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		if (!arg->cmd[idx]->cmd_path)
			print_error(3, arg);
		if (execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, arg->envp) == -1)
			print_error(4, arg);
	}
	else
	{
		close(fd[1]);
		close(fd[0]);
		waitpid(pid, &status, 0);
		free_all(arg);
		if (WIFSIGNALED(status))
			exit(WTERMSIG(status));
	}
}

//norm 정리
//자식에서 print_error하는거 부모에서 하는걸로 바꿔주기
