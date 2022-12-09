/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 16:16:05 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	r_infile(t_data *data, char *file)
{
	if (access(file, F_OK) == -1 || access(file, R_OK) == -1)
	{
		perror(file);
		data->exit_code = 1;
		data->err_flag = 1;
		return (1);
	}
	if (data->infile_fd != -1)
		close(data->infile_fd);
	data->infile_fd = open(file, O_RDONLY);
	if (data->infile_fd < 0)
	{
		perror(file);
		data->exit_code = 1;
		data->err_flag = 1;
		return (1);
	}
	if (dup2(data->infile_fd, 0) == -1)
	{
		perror("Dup Error :");
		exit(1);
	}
	return (0);
}

static int	r_outfile(t_data *data, char *file)
{
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	data->outfile_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile_fd < 0)
	{
		perror(file);
		data->exit_code = 1;
		data->err_flag = 1;
		return (1);
	}
	if (dup2(data->outfile_fd, 1) == -1)
	{
		perror("Dup Error :");
		exit(1);
	}
	return (0);
}

static int	r_appendfile(t_data *data, char *file)
{
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	if (access(file, F_OK) == -1)
		data->outfile_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		data->outfile_fd = open(file, O_RDWR | O_APPEND, 0644);
	if (data->outfile_fd < 0)
	{
		perror(file);
		data->exit_code = 1;
		data->err_flag = 1;
		return (1);
	}
	if (dup2(data->outfile_fd, 1) == -1)
	{
		perror("Dup Error :");
		exit(1);
	}
	return (0);
}

static void	exe_rdir(t_data *data, char *rdir, char *file)
{
	if (!ft_strncmp(rdir, "<<", 2))
	{
		if (r_heredoc(data, file))
			return ;
	}
	else if (!ft_strncmp(rdir, "<", 1))
	{
		if (r_infile(data, file))
			return ;
	}
	else if (!ft_strncmp(rdir, ">>", 2))
	{
		if (r_appendfile(data, file))
			return ;
	}
	else if (!ft_strncmp(rdir, ">", 1))
	{
		if (r_outfile(data, file))
			return ;
	}
}

void	set_rdir(t_data *data, t_node *n)
{
	char	*rdir;
	char	*file;
	int		idx;

	idx = -1;
	while (n->node_str[++idx] && ft_strchr("<> ", n->node_str[idx]))
		;
	if (!n->node_str[idx])
	{
		write(2, "Syntax Error\n", ft_strlen("Syntax Error\n"));
		data->exit_code = 1;
		data->err_flag = 1;
		return ;
	}
	decode_text(n->node_str);
	rdir = str_cut_front(n->node_str, idx + 1);
	file = str_cut_back(n->node_str, idx - 1);
	exe_rdir(data, rdir, file);
	free(rdir);
	free(file);
}
