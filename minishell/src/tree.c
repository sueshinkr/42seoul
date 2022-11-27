#include "minishell.h"

char *arr[] = {"WORD", "PIPE", "CMD", "SCMD", "RDIRS", "RDIR"};

node	*init_node(node *n)
{
	node *new = (node *)malloc(sizeof(node));
	new->type = WORD;
	if (n)
	{
		new->pipe = n->pipe;
		new->level = n->level + 1;
	}
	else
	{
		new->pipe = 0;
		new->level = 0;
	}
	new->left = NULL;
	new->right = NULL;
	new->node_str = NULL;
	return (new);
}

void	make_tree(t_data *data, char *str, node *n)
{
	int	idx;

	idx = -1;
	n->node_str = str;
	while (str[++idx])
	{
		if (case_pipe(data, str, n, idx))
			return ;
		if (case_cmd(data, str, n, idx))
			return ;
		if (case_rdir(data, str, n, idx))
			return ;
	}
	if (n->type == WORD)
	{
		n->type = CMD;
		make_tree(data, str, n);
	}
}

/*
void	print_tree(node *n)
{
	if (n->left)
		print_tree(n->left);
	if (n->right)
		print_tree(n->right);

	printf("==============\n");
	decode_text(n->node_str);
	printf("%s\n", n->node_str);
	printf("type : %s\n", arr[n->type]); 
	printf("level : %d\n", n->level);
}
*/

void	search_tree(t_data *data, node *n)
{
	if (n->left)
		search_tree(data, n->left);
	if (n->right)
		search_tree(data, n->right);
	if (n->type == PIPE)
	{
		close(data->infile_fd);
		close(data->outfile_fd);
		data->infile_fd = -1;
		data->outfile_fd = -1;
		dup2(0, data->stdin_fd);
		dup2(0, data->stdout_fd);
	}
	else if (n->type == RDIR)
	{
		//printf("::::RDIR::::\n");
		//decode_text(n->node_str);
		//printf("::%s\n", n->node_str);
		set_rdir(data, n);
	}
	else if (n->type == SCMD)
	{
		// 빌트인인지 아닌지 구분
		// 아니면 명령어 경로 찾아서 exec
		//printf("::::SCMD::::\n");
		set_scmd(data, n);
	}
}

void init_tree(char *line, t_data *data)
{
	node *head = init_node(NULL);
	data->head = head;

	char *temp;

	temp = set_text(line, data);
	make_tree(data, temp, head);
	free(temp);

	data->stdin_fd = dup(0);
	data->stdout_fd = dup(1);
	data->last_pipe[0] = -1;
	data->last_pipe[1] = -1;
	search_tree(data, head);
	close(data->last_pipe[0]);
	close(data->last_pipe[1]);
	dup2(data->stdin_fd, 0);
	dup2(data->stdout_fd, 1);
}
