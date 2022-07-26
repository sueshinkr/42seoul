/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:05:00 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 18:01:30 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *infile, t_arg *arg)
{
	int	fd;

	if (check_file(infile) == 0)
	{
		fd = open(infile, O_RDONLY);
		if (fd < 0)
			print_error(2, arg);
	}
	else
	{
		perror("INFILE Error");
		fd = 0;
	}
	return (fd);
}

int	open_outfile(char *outfile, t_arg *arg)
{
	int	fd;
	int	mode;

	mode = O_CREAT | O_RDWR | O_TRUNC;
	fd = open(outfile, mode, 0644);
	if (fd < 0)
		print_error(2, arg);
	return (fd);
}

int	open_outfile_here(char *outfile, t_arg *arg)
{
	int	fd;
	int	mode;

	if (access(outfile, F_OK) == -1)
	{
		mode = O_CREAT | O_RDWR | O_TRUNC;
		fd = open(outfile, mode, 0644);
	}
	else
	{
		mode = O_RDWR | O_APPEND;
		fd = open(outfile, mode, 0644);
	}
	if (fd < 0)
		print_error(2, arg);
	return (fd);
}
