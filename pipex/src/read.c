/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:02:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/25 04:55:18 by sueshin          ###   ########.fr       */
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

int	open_outfile(char *outfile, t_arg *arg)
{
	int	fd;
	int	mode;

	mode = O_CREAT | O_RDWR | O_TRUNC;
	fd = open(outfile, mode, 0755);
	if (fd < 0)
		print_error(4, arg);
	return (fd);
}

int	open_outfile_here(char *outfile, t_arg *arg)
{
	int	fd;
	int	mode;

	if (access(outfile, F_OK) == -1)
	{
		mode = O_CREAT | O_RDWR | O_TRUNC;
		fd = open(outfile, mode, 0755);
	}
	else
	{
		mode = O_CREAT | O_RDWR | O_APPEND;
		fd = open(outfile, mode, 0755);
	}
	if (fd < 0)
		print_error(4, arg);
	return (fd);
}

static void	read_arg_here(int num, char **argv, char **envp, t_arg *arg)
{
	int		idx;
	char	*str;
	idx = -1;
	int		fd;

	fd = open("heredoc_temp", O_CREAT | O_RDWR | O_TRUNC, 0755);
	if (fd < 0)
	{
		unlink("heredoc_temp");
		print_error(4, arg);
	}
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
			write(fd, str, ft_strlen(str));
			free(str);
		}
	}
	close(fd);
	open_infile("heredoc_temp", arg);
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
	check_file(argv[1], arg);
	open_infile(argv[1], arg);
	arg->path = find_enpath(envp);
	while (++idx < num)
	{
		arg->cmd[idx] = malloc(sizeof(t_cmd));
		arg->cmd[idx]->cmd_str = ft_split(argv[idx + 2], ' ');
		arg->cmd[idx]->cmd_path = check_path(arg->path, arg->cmd[idx]->cmd_str[0]);
		arg->cmd_num++;
	}
}
