/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 16:20:47 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_input(int fd[2], char **argv)
{
	char	*str;

	close(fd[0]);
	dup2(fd[1], 1);
	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(argv[2], str, ft_strlen(argv[2])) == 0)
		{
			free(str);
			break ;
		}
		else
		{
			write(1, str, ft_strlen(str));
			free(str);
		}
	}
	return ;
}

static void	read_arg_here(int num, char **argv, char **envp, t_arg *arg)
{
	int		idx;
	char	*str;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		print_error(5, arg);
	pid = fork();
	if (pid == 0)
	{
		get_input(fd, argv);
		return ;
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	idx = -1;
	arg->path = find_enpath(envp);
	while (++idx < num)
	{
		arg->cmd[idx] = malloc(sizeof(t_cmd));
		arg->cmd[idx]->cmd_str = ft_split(argv[idx + 3], ' ');
		arg->cmd[idx]->cmd_path = \
			check_path(arg->path, arg->cmd[idx]->cmd_str[0]);
		arg->cmd_num++;
	}
}

void	read_arg(int num, char **argv, char **envp, t_arg *arg)
{
	int	idx;

	idx = -1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		arg->is_here = 1;
		read_arg_here(num - 1, argv, envp, arg);
		return ;
	}
	arg->path = find_enpath(envp);
	while (++idx < num)
	{
		arg->cmd[idx] = malloc(sizeof(t_cmd));
		arg->cmd[idx]->cmd_str = ft_split(argv[idx + 2], ' ');
		arg->cmd[idx]->cmd_path = \
			check_path(arg->path, arg->cmd[idx]->cmd_str[0]);
		arg->cmd_num++;
	}
}
