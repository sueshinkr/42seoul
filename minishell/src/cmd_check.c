/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:02:53 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:41 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *data, char **cmd_str)
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
		return (0);
	return (1);
}

static int	is_inslash(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (1);
		s++;
	}
	return (0);
}

char	*check_path(t_list *env, t_data *data, char *cmd)
{
	char	**path;

	path = 0;
	if (is_inslash(cmd) && !access(cmd, F_OK))
	{
		if (!access(cmd, X_OK))
			return (ft_strdup(cmd));
		data->exit_code = 126;
		return (NULL);
	}
	while (env && env->key)
	{
		if (!ft_strcmp(env->key, "PATH"))
			path = ft_split(env->value, ':');
		env = env->next;
	}
	if (path == NULL)
		return (NULL);
	return (ret_path(data, path, cmd));
}

static char	*check_slash(char *path, char *cmd)
{
	char	*temp;
	char	*ret;
	int		len;

	if (cmd[0] == '/')
		return (ft_strdup(cmd));
	len = ft_strlen(path);
	if (path[len - 1] == '/')
		ret = ft_strjoin_nofree(path, cmd);
	else
	{
		temp = ft_strjoin_nofree("/", cmd);
		ret = ft_strjoin_nofree(path, temp);
		free(temp);
	}
	return (ret);
}

char	*ret_path(t_data *data, char **path, char *cmd)
{
	char	*str;
	int		idx;

	idx = 0;
	while (path[idx])
	{
		str = check_slash(path[idx], cmd);
		if (!access(str, F_OK))
		{
			free_arr(path);
			return (str);
		}
		else
			free(str);
		idx++;
	}
	data->exit_code = 127;
	free_arr(path);
	return (NULL);
}
