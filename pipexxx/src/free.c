/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:12:19 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 02:05:37 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd(t_arg *arg)
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

static void	free_path(t_arg *arg)
{
	int	idx;

	idx = -1;
	while (arg->path[++idx])
		free(arg->path[idx]);
	free(arg->path);
}

void	free_all(t_arg *arg)
{
	free_cmd(arg);
	free_path(arg);
	free(arg);
}

void	print_error(int num, t_arg *arg)
{
	if (num == 1)
	{
		write(2, "ARG Error\n", 10);
		free(arg);
		exit(1);
	}
	else if (num == 2)
	{
		write(2, "FILE Error\n", 11);
		free_all(arg);
		exit(1);
	}
	else if (num == 3)
	{
		write(2, "CMD Error\n", 10);
		free_all(arg);
		exit(127);
	}
	else if (num == 4)
	{
		write(2, "EXEC Error\n", 11);
		free_all(arg);
		exit(1);
	}
}
