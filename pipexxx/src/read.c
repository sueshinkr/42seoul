/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/26 02:03:51 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *infile, t_arg *arg)
{
	int	fd;
	int mode;

	if (check_file(infile) == 0)
	{
		fd = open(infile, O_RDONLY);
		if (fd < 0)
			print_error(2, arg);
	}
	else
		fd = 0;
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

static void	read_arg_noinfile(void)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		return ;
	}
	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, &status, 0);
}

static void	read_arg_here(int num, char **argv, char **envp, t_arg *arg)
{
	int		idx;
	char	*str;
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		while (1)
		{
			str = get_next_line(0);
			if (ft_strncmp(argv[2], str, ft_strlen(argv[2])) == 0)
			{
				free(str);
				break;
			}
			else
			{
				write(1, str, ft_strlen(str));
				free(str);
			}
		}
		return ;
	}
	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, &status, 0);
	idx = -1;
	arg->path = find_enpath(envp);
	while (++idx < num)
	{
		arg->cmd[idx] = malloc(sizeof(t_cmd));
		arg->cmd[idx]->cmd_str = ft_split(argv[idx + 3], ' ');
		arg->cmd[idx]->cmd_path = check_path(arg->path, arg->cmd[idx]->cmd_str[0]);
		arg->cmd_num++;
	}
}

void	read_arg(int num, char **argv, char **envp, t_arg *arg)
{
	int	idx = -1;

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
		arg->cmd[idx]->cmd_path = check_path(arg->path, arg->cmd[idx]->cmd_str[0]);
		arg->cmd_num++;
	}
}
