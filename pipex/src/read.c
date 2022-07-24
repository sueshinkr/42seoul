/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/24 21:55:34 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_infile(char *infile, t_arg *arg)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		print_error(4, arg);
	else
	{
		dup2(fd, 0);
		close(fd);
	}
}

/*
void	open_outfile(char *outfile, t_arg *arg)
{
	int	fd;
	int	mode;

	mode = O_CREAT | O_RDWR | O_TRUNC;
	fd = open(outfile, mode, 0755);
	if (fd < 0)
		print_error(4, arg);
	else
	{
		dup2(fd, 1);
		close(fd);
	}
}
*/

int	open_outfile(char *outfile, t_arg *arg)
{
	int	fd;
	int	mode;

	mode = O_CREAT | O_RDWR | O_TRUNC;
	fd = open(outfile, mode, 0755);
	if (fd < 0)
		print_error(4, arg);
	//else
	return (fd);
}

void	read_arg(int num, char **argv, char **envp, t_arg *arg)
{
	int	idx = -1;

	check_file(argv[1], arg);
	open_infile(argv[1], arg);
	arg->path = find_enpath(envp);

	while (++idx < num)
	{
		arg->cmd[idx] = malloc(sizeof(t_cmd));
		arg->cmd[idx]->cmd_str = ft_split(argv[idx + 2], ' ');
		arg->cmd[idx]->cmd_path = check_path(arg->path, arg->cmd[idx]->cmd_str[0]);
		arg->cmd_num++;
		//if (!arg->cmd[idx]->cmd_path)
		//	print_error(3, arg);
	}
}
