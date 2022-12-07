/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:01 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:45:29 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_env(t_data *data, int len)
{
	t_list	*temp;
	char	**env;
	int		idx;

	temp = data->env;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	env = malloc((len + 1) * sizeof(char *));
	temp = data->env;
	idx = -1;
	while (temp->key)
	{
		if (temp->value)
		{
			env[++idx] = ft_strdup(temp->key);
			env[idx] = ft_strjoin_gnl(env[idx], "=");
			env[idx] = ft_strjoin_gnl(env[idx], temp->value);
		}
		temp = temp->next;
	}
	env[++idx] = 0;
	return (env);
}

void	prt_execute_err(t_data *data)
{
	if (data->exit_code == 126)
		write(2, "permission denied\n", ft_strlen("permission denied\n"));
	else
		write(2, "command not found\n", ft_strlen("command not found\n"));
	return ;
}

static void	do_exec(t_data *data, char *cmd_path, char **cmd_str, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork :");
		exit(1);
	}
	if (pid == 0)
	{
		execve(cmd_path, cmd_str, env);
		perror(cmd_str[0]);
		exit(errno);
	}
	waitpid(pid, &data->exit_code, 0);
	data->exit_code = data->exit_code >> 8;
	data->pid = 0;
}

void	single_cmd(t_data *data, char **cmd_str, char **env)
{
	char	*cmd_path;

	if (is_builtin(data, cmd_str))
		;
	else
	{
		cmd_path = check_path(data->env, data, cmd_str[0]);
		if (!cmd_path)
		{
			prt_execute_err(data);
			return ;
		}
		do_exec(data, cmd_path, cmd_str, env);
		free(cmd_path);
	}
}

void	set_scmd(t_data *data, t_node *n)
{
	char	**cmd_str;
	char	**env;
	int		idx;

	idx = -1;
	data->cmd_cnt++;
	cmd_str = ft_split(n->node_str, ' ');
	while (cmd_str[++idx])
		decode_text(cmd_str[idx]);
	env = make_env(data, 0);
	if (data->pipe_num < 1)
		single_cmd(data, cmd_str, env);
	else
		pipe_cmd(data, cmd_str, env);
	free_arr(cmd_str);
	free_arr(env);
	unlink("/tmp/here_doc");
}
