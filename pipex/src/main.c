/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 16:22:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_arg	*init_arg(int argc, char **envp)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(1);
	if (argc < 5)
		print_error(1, arg);
	arg->cmd = malloc(sizeof(t_cmd *) * (argc - 3));
	arg->cmd_num = 0;
	arg->envp = envp;
	arg->is_error = 0;
	arg->is_here = 0;
	return (arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;
	int		idx;
	int		fdin;
	int		fdout;

	arg = init_arg(argc, envp);
	read_arg(argc - 3, argv, envp, arg);
	if (arg->is_here == 0)
	{
		fdin = open_infile(argv[1], arg);
		dup2(fdin, 0);
		fdout = open_outfile(argv[argc - 1], arg);
	}
	else
	{
		fdin = -1;
		fdout = open_outfile_here(argv[argc - 1], arg);
	}
	idx = -1;
	while (++idx < argc - 5 - arg->is_here)
		pipe_in(arg, idx, fdin);
	pipe_last(arg, idx, fdin, fdout);
	return (0);
}
