#include "minishell.h"

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

	printf("rdir:%s, file :%s!\n", rdir, file);

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
		;
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
}