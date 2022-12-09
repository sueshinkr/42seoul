/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:06 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:46 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **argvs, t_data *data)
{
	char	*path;

	if (argvs[1] == 0)
	{
		path = get_env("HOME", data->env);
		if (path == NULL)
		{
			errno = 1;
			write(2, "cd: HOME not set\n", ft_strlen("cd: HOME not set\n"));
			return (1);
		}
	}
	else
		path = ft_strdup(argvs[1]);
	if (chdir(path) == -1)
	{
		free(path);
		perror(argvs[0]);
		return (1);
	}
	free(path);
	return (0);
}
