#include "minishell.h"

static int	ft_newline_strcmp(char *s1, char *s2)
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

static int	read_heredoc(char *delimiter, t_data *data)
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
		write(fd, tmp, ft_strlen(tmp));
		free(tmp);
	}
	return (open("here_doc", O_RDONLY, 0644));
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
