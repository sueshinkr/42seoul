#include "minishell.h"

int	case_pipe(t_data *data, char *str, node *n, int idx)
{
	if (str[idx] == '|')
	{
		data->pipe_num++;
		n->type = PIPE;
		n->left = init_node();
		n->left->type = CMD;
		make_tree(data, str_cut_front(str, idx), n->left);
		n->right = init_node();
		make_tree(data, str_cut_back(str, idx), n->right);
		return (1);
	}
	return (0);
}

