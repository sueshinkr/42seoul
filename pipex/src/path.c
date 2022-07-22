/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:31:18 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 15:21:53 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(char *argv)
{
	int	mode;

	mode = F_OK | X_OK;
	if (access(argv, mode) == -1)
		print_error(2);
}

char	**find_enpath(char **envp)
{
	int		idx;
	char	**path;

	idx = -1;
	while (envp[++idx])
	{
		if (!ft_strncmp(envp[idx], "PATH=", 5))
			path = ft_split(envp[idx], ':');
	}
	return (path);
}

static char	*check_slash(char *path, char *cmd)
{
	char	*return_cmd;
	char	*temp;
	int		len;

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
	int		len;
	char	*str;

	idx = -1;
	while (path[++idx])
	{
		str = check_slash(path[idx], cmd);
		if (!access(str, F_OK))
			return (str);
		free(str);
	}
	return (NULL);
}
