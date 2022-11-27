#include "minishell.h"

void	get_input(int fd[2], char *file)
{
	char	*str;

	close(fd[0]);
	dup2(fd[1], 1);
	while (1)
	{
		str = get_next_line(0);
		if (strncmp(file, str, strlen(file)) == 0)
		{
			free(str);
			break;
		}
		else
		{
			write(1, str, strlen(str));
			free(str);
		}
	}
	return ;
}

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
		printf("File Open Error");
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

void	set_rdir(t_data *data, node *n)
{
	char	*rdir;
	char	*file;
	int		idx = -1;
	// < 분리

	while (strchr("<>", n->node_str[++idx]))
		;
	rdir = str_cut_front(n->node_str, idx + 1);
	file = str_cut_back(n->node_str, idx - 1);

	//printf("rdir:%s, file :%s!\n", rdir, file);

	if (!strcmp(rdir, "<"))
	{
		if (access(file, F_OK) == -1)
			printf("access error\n");
		if (data->infile_fd != -1)
			close(data->infile_fd);
		data->infile_fd = open(file, O_RDONLY);
		if (data->infile_fd < 0)
			printf("open error\n");
		if (dup2(data->infile_fd, 0) == -1)
			printf("dup error\n");
	}
	else if (!strcmp(rdir, "<<"))
	{
		if (data->infile_fd != -1)
			close(data->infile_fd);
		data->infile_fd = read_heredoc(file, data);
		if (dup2(data->infile_fd, 0) == -1)
			printf("dup error\n");
	}
	else if (!strcmp(rdir, ">"))
	{
		if (data->outfile_fd != -1)
			close(data->outfile_fd);
		data->outfile_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->outfile_fd < 0)
			printf("open error\n");
		if (dup2(data->outfile_fd, 1) == -1)
			printf("dup error\n");
	}
	else if (!strcmp(rdir, ">>"))
	{
		if (data->outfile_fd != -1)
			close(data->outfile_fd);
		if (access(file, F_OK) == -1)
			data->outfile_fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
			data->outfile_fd = open(file, O_RDWR | O_APPEND, 0644);
		if (data->outfile_fd < 0)
			printf("open error\n");
		if (dup2(data->outfile_fd, 1) == -1)
			printf("dup error\n");
	}
	free(rdir);
	free(file);
}