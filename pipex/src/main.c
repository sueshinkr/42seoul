/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:59 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/24 12:09:13 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_arg	*init_arg(int argc, char **envp)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(1);
	arg->cmd = malloc(sizeof(t_cmd *) * (argc - 3));
	arg->cmd_num = 0;
	arg->envp = envp;
	return (arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg; 
	int		idx;
	char	*str;

	arg = init_arg(argc, envp);
	if (argc < 5)
		print_error(1, arg);
	read_arg(argc - 3, argv, envp, arg);
	idx = -1;
	while (++idx < argc - 4)
		pipe_in(arg, idx);
	open_outfile(argv[argc - 1], arg);
	pipe_in_last(arg, idx);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return (0);
		else
		{
			ft_printf("%s", str);
			free(str);
		}
	}
/*
	if (!arg->cmd[idx]->cmd_path)
	{
		free_cmd(arg);
		free_path(arg);
		free(arg);
		exit(arg->exit_code);
	}
	if (execve(arg->cmd[idx]->cmd_path, arg->cmd[idx]->cmd_str, envp) == -1)
		print_error(4, arg);
*/
}
