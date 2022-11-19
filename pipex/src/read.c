/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/11/19 16:23:56 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_input(int fd[2], char **argv, t_arg *arg)
{
	char	*str;

	close(fd[0]);
	dup_check(fd[1], 1, arg);
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

static void	read_arg_here(char **argv, t_arg *arg)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		print_error(5, arg);
	pid = fork();
	if (pid == -1)
		print_error(7, arg);
	if (pid == 0)
	{
		get_input(fd, argv, arg);
		exit(0);
	}
	close(fd[1]);
	dup_check(fd[0], 0, arg);
	waitpid(pid, NULL, 0);
}

void	read_arg(int num, char **argv, char **envp, t_arg *arg)
{
	int	i;

	i = -1;
	arg->path = find_enpath(envp);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		arg->is_here = 1;
		read_arg_here(argv, arg);
		while (++i < num - 1)
		{
			arg->cmd[i] = malloc(sizeof(t_cmd));
			arg->cmd[i]->cmd_str = ft_split(argv[i + 3], ' ');
			arg->cmd[i]->cmd_path = check_path(arg->path, \
											arg->cmd[i]->cmd_str[0]);
			arg->cmd_num++;
		}
		return ;
	}
	while (++i < num)
	{
		arg->cmd[i] = malloc(sizeof(t_cmd));
		arg->cmd[i]->cmd_str = ft_split(argv[i + 2], ' ');
		arg->cmd[i]->cmd_path = check_path(arg->path, arg->cmd[i]->cmd_str[0]);
		arg->cmd_num++;
	}
}
