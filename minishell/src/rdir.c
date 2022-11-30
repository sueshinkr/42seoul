#include "minishell.h"

int	ft_newline_strcmp(char *s1, char *s2)
{
	while (*s1 != '\n' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	if (*s1 == '\n' && *s2 == '\0')
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	read_heredoc(char *delimiter, t_data *data)
{
	int		fd;
	char	*tmp;

	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	while (1)
	{
		write(1, "here_doc> ", 10);
		tmp = get_next_line(data->stdin_fd);
		if (ft_newline_strcmp(tmp, delimiter) == 0)
		{
			free(tmp);
			close(fd);
			break ;
		}
		write(fd, tmp, strlen(tmp));
		free(tmp);
	}
	return (open("here_doc", O_RDONLY, 0644));
}

int	r_infile(t_data *data, char *file)
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

int	r_heredoc(t_data *data, char *delimeter)
{
	if (data->infile_fd != -1)
		close(data->infile_fd);
	data->infile_fd = read_heredoc(delimeter, data);
	if (data->infile_fd < 0)
	{
		perror("heredoc");
		data->exit_code = 1;
		data->err_flag = 1;
	}
	if (dup2(data->infile_fd, 0) == -1)
	{
		perror("Dup Error :");
		exit(1);
	}
	return (0);
}

int	r_outfile(t_data *data, char *file)
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

int	r_appendfile(t_data *data, char *file)
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

void	exe_rdir(t_data *data, char *rdir, char *file)
{
	if (!strcmp(rdir, "<"))
	{
		if (r_infile(data, file))
			return ;
	}
	else if (!strcmp(rdir, "<<"))
	{
		if (r_heredoc(data, file))
			return ;
	}
	else if (!strcmp(rdir, ">"))
	{
		if (r_outfile(data, file))
			return ;
	}
	else if (!strcmp(rdir, ">>"))
	{
		if (r_appendfile(data, file))
			return ;
	}
}

void	set_rdir(t_data *data, node *n)
{
	char	*rdir;
	char	*file;
	int		idx;

	idx = -1;
	while (n->node_str[++idx] && strchr("<>", n->node_str[idx]))
		;
	if (!n->node_str[idx])
	{
		write(2, "Syntax Error\n", ft_strlen_gnl("Syntax Error\n"));
		data->exit_code = 1;
		data->err_flag = 1;
		return ;
	}
	rdir = str_cut_front(n->node_str, idx + 1);
	file = str_cut_back(n->node_str, idx - 1);
	exe_rdir(data, rdir, file);
	free(rdir);
	free(file);
}