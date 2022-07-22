/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 19:08:12 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		print_error(4);
	else
	{
		dup2(fd, 0);
		close(fd);
	}
}

void	open_outfile(char *outfile)
{
	int	fd;
	int	mode;

	mode = O_CREAT | O_RDWR | O_TRUNC;
	fd = open(outfile, mode, 0755);
	if (fd < 0)
		print_error(4);
	else
	{
		dup2(fd, 1);
		close(fd);
	}
}

void	read_arg(char **argv, char **envp, t_list *arg)
{
	int		idx = 0;

	check_file(argv[1]);
	open_infile(argv[1]);
	arg->path = find_enpath(envp);
	arg->cmd1 = ft_split(argv[2], ' ');
	arg->cmd2 = ft_split(argv[3], ' ');
	arg->path_cmd1 = check_path(arg->path, arg->cmd1[0]);
	arg->path_cmd2 = check_path(arg->path, arg->cmd2[0]);
	if (!arg->path_cmd1 || !arg->path_cmd2)
		print_error(3);
}