#include "minishell.h"

t_node	*init_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->type = WORD;
	new->left = NULL;
	new->right = NULL;
	new->node_str = NULL;
	return (new);
}

void	make_tree(t_data *data, char *str, t_node *n)
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

void	search_tree(t_data *data, t_node *n)
{
	if (n->left)
		search_tree(data, n->left);
	if (n->right)
		search_tree(data, n->right);
	if (n->type == PIPE)
		;
	else if (n->type == RDIR)
	{
		if (!data->err_flag)
			set_rdir(data, n);
	}
	else if (n->type == SCMD)
	{
		if (!data->err_flag)
			set_scmd(data, n);
		data->err_flag = 0;
		close(data->infile_fd);
		close(data->outfile_fd);
		data->infile_fd = -1;
		data->outfile_fd = -1;
		dup2(data->stdin_fd, 0);
		dup2(data->stdout_fd, 1);
	}
}

void	init_tree(char *line, t_data *data)
{
	t_node	*head;
	char	*parsed_line;

	head = init_node();
	data->head = head;
	parsed_line = parse_line(line, data);
	make_tree(data, parsed_line, head);
	data->cmd_cnt = -1;
	data->last_pipe[0] = -1;
	data->last_pipe[1] = -1;
	search_tree(data, head);
	close(data->last_pipe[0]);
	close(data->last_pipe[1]);
	data->last_pipe[0] = -1;
	data->last_pipe[1] = -1;
	data->err_flag = 0;
	dup2(data->stdin_fd, 0);
	dup2(data->stdout_fd, 1);
	waitpid(data->pid, &data->exit_code, 0);
	while (wait(0) != -1)
		;
}

void	free_tree(t_data *data, t_node *n)
{
	if (n->left)
		free_tree(data, n->left);
	if (n->right)
		free_tree(data, n->right);
	free(n->node_str);
	free(n);
}
