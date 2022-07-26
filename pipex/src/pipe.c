/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 18:47:43 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	last_child(t_arg *arg, int idx)
{
	if (!arg->cmd[idx]->cmd_path)
		print_error(3, arg);
	if (execve(arg->cmd[idx]->cmd_path, \
				arg->cmd[idx]->cmd_str, arg->envp) == -1)
		print_error(4, arg);
}

static void	last_parent(t_arg *arg, int idx)
{
	if (!arg->cmd[idx]->cmd_path)
		arg->is_error = 3;
	if (execve(arg->cmd[idx]->cmd_path, \
				arg->cmd[idx]->cmd_str, arg->envp) == -1)
	{
		if (arg->is_error == 3)
			print_error(3, arg);
		print_error(4, arg);
	}
}

void	pipe_last(t_arg *arg, int idx, int fdin, int fdout)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		print_error(5, arg);
	pid = fork();
	if (pid == -1)
		print_error(7, arg);
	if (pid == 0)
	{
		close(fd[0]);
		dup_check(fd[1], 1, arg);
		if (fdin == 0)
			exit(1);
		last_child(arg, idx);
	}
	else
	{
		close(fd[1]);
		dup_check(fd[0], 0, arg);
		dup_check(fdout, 1, arg);
		waitpid(pid, NULL, WNOHANG);
		last_parent(arg, ++idx);
	}
}

void	pipe_in(t_arg *arg, int idx, int fdin)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		print_error(5, arg);
	pid = fork();
	if (pid == -1)
		print_error(7, arg);
	if (pid == 0)
	{
		close(fd[0]);
		dup_check(fd[1], 1, arg);
		if (fdin == 0)
			exit(1);
		if (!arg->cmd[idx]->cmd_path)
			print_error(3, arg);
		if (execve(arg->cmd[idx]->cmd_path, \
					arg->cmd[idx]->cmd_str, arg->envp) == -1)
			print_error(4, arg);
		return ;
	}
	close(fd[1]);
	dup_check(fd[0], 0, arg);
	waitpid(pid, NULL, WNOHANG);
}
