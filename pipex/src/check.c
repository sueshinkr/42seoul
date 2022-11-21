/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:31:18 by sueshin           #+#    #+#             */
/*   Updated: 2022/11/21 16:43:59 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_check(int to, int from, t_arg *arg)
{
	if (dup2(to, from) == -1)
		print_error(6, arg);
}

int	check_file(char *argv)
{
	int	mode;

	mode = F_OK;
	if (access(argv, mode) == -1)
		return (-1);
	return (0);
}

char	**find_enpath(char **envp)
{
	int		idx;
	char	**path;

	idx = -1;
	while (envp[++idx])
	{
		if (!ft_strncmp(envp[idx], "PATH=", 5))
			path = ft_split(envp[idx] + 5, ':');
	}
	return (path);
}

static char	*check_slash(char *path, char *cmd)
{
	char	*return_cmd;
	char	*temp;
	int		len;

	if (cmd[0] == '/')
		return (ft_strdup(cmd));
	len = ft_strlen(path);
	if (path[len - 1] == '/')
		return_cmd = ft_strjoin_pipex(path, cmd);
	else
	{
		temp = ft_strjoin_pipex("/", cmd);
		return_cmd = ft_strjoin_pipex(path, temp);
		free(temp);
	}
	return (return_cmd);
}

char	*check_path(char **path, char *cmd)
{
	int		idx;
	char	*str;

	idx = -1;
	while (path[++idx])
	{
		str = check_slash(path[idx], cmd);
		if (!access(str, F_OK))
			return (str);
		else
			free(str);
	}
	return (NULL);
}
