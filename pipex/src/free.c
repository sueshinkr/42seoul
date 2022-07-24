/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:12:19 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/25 01:27:41 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arg(t_arg *arg)
{
	free(arg->cmd);
	free(arg);
}

void	free_cmd(t_arg *arg)
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

void	free_path(t_arg *arg)
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
		free(arg);
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
		exit(1);
	}
}
