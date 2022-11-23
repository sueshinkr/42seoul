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

void	read_arg(char *file)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		printf("pipe error\n");
	pid = fork();
	if (pid == -1)
		printf("error\n");
	if (pid == 0)
	{
		get_input(fd, file);
		exit(0);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, NULL, 0);
}

void set_rdir(node *n)
{
	char	*rdir;
	char	*file;
	int		fd;
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
		fd = open(file, O_RDONLY);
		if (fd < 0)
			printf("open error\n");
		if (dup2(fd, 0) == -1)
			printf("dup error\n");
	}
	else if (!strcmp(rdir, "<<"))
	{
		read_arg(file);
	}
	else if (!strcmp(rdir, ">"))
	{
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
			printf("open error\n");
		if (dup2(fd, 1) == -1)
			printf("dup error\n");
	}
	else if (!strcmp(rdir, ">>"))
	{
		if (access(file, F_OK) == -1)
			fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
			fd = open(file, O_RDWR | O_APPEND, 0644);
		if (fd < 0)
			printf("open error\n");
		if (dup2(fd, 1) == -1)
			printf("dup error\n");
	}

	free(rdir);
	free(file);
}