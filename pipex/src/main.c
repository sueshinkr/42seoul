/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/25 18:19:37 by sueshin          ###   ########.fr       */
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

	arg = init_arg(argc, envp);
	if (argc < 5)
		print_error(1, arg);
	read_arg(argc - 3, argv, envp, arg);
	idx = -1;
	while (++idx < argc - 4 - arg->is_here)
		pipe_in(arg, idx);
	pipe_in_last(arg, argv, argc, idx);
	free_cmd(arg);
	free_path(arg);
	free(arg);
	return (0);
}
