/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:57 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:42 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_src(int *p)
{
	dup2(p[1], 1);
	close(p[0]);
}

static void	dup_dest(t_data *data, int *p)
{
	if (data->infile_fd == -1)
		dup2(data->last_pipe[0], 0);
	else
		dup2(data->infile_fd, 0);
	if (data->cmd_cnt < data->pipe_num)
	{
		dup2(p[1], 1);
		close(p[0]);
	}
	else
	{
		dup2(data->outfile_fd, 1);
	}
	close(data->last_pipe[1]);
}

static void	pipe_in(char *cmd_path, char **cmd_str, char **env, t_data *data)
{
	if (!ft_strcmp(cmd_str[0], "echo"))
		data->exit_code = ft_echo(cmd_str);
	else if (!ft_strcmp(cmd_str[0], "cd"))
		data->exit_code = ft_cd(cmd_str, data);
	else if (!ft_strcmp(cmd_str[0], "pwd"))
		data->exit_code = ft_pwd(cmd_str);
	else if (!ft_strcmp(cmd_str[0], "export"))
		data->exit_code = ft_export(cmd_str, data);
	else if (!ft_strcmp(cmd_str[0], "unset"))
		data->exit_code = ft_unset(cmd_str, data);
	else if (!ft_strcmp(cmd_str[0], "env"))
		data->exit_code = ft_env(cmd_str, data->env);
	else if (!ft_strcmp(cmd_str[0], "exit"))
		data->exit_code = ft_exit(cmd_str);
	else
		execve(cmd_path, cmd_str, env);
	exit(data->exit_code);
}

static void	close_pipe(t_data *data, int *p)
{
	close(data->last_pipe[0]);
	close(data->last_pipe[1]);
	data->last_pipe[0] = p[0];
	data->last_pipe[1] = p[1];
}

void	pipe_cmd(t_data *data, char **cmd_str, char **env)
{
	char	*cmd_path;
	pid_t	pid;
	int		p[2];

	cmd_path = check_path(data->env, data, cmd_str[0]);
	if (!cmd_path)
		return (prt_execute_err(data));
	if (pipe(p) == -1)
	{
		perror("Pipe Error : ");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (data->last_pipe[0] == -1)
			dup_src(p);
		else
			dup_dest(data, p);
		pipe_in(cmd_path, cmd_str, env, data);
	}
	data->pid = pid;
	close_pipe(data, p);
	free(cmd_path);
}
