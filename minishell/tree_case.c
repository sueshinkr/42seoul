#include "minishell.h"

int	case_pipe(char *str, node *n, int idx)
{
	if (str[idx] == '|')
	{
		n->type = PIPE;
		n->left = init_node(n);
		n->left->pipe++;
		n->left->type = CMD;
		make_tree(str_cut_front(str, idx), n->left);
		n->right= init_node(n);
		make_tree(str_cut_back(str, idx), n->right);
		return (1);
	}
	return (0);
}

int	case_cmd(char *str, node *n, int idx)
{
	if (n->type == CMD && strchr("<>", str[idx]))
	{
		case_rdir_cmd(str, n, idx);
		return (1);
	}
	if (n->type == CMD && !strchr("<> ", str[idx]))
	{
		while (str[++idx])
		{
			if (strchr("<>", str[idx]) && str[idx - 1] != -1)
			{
				case_cmd_rdir(str, n, idx);
				return (1);
			}
		}
		case_scmd(str, n);
		return (1);
	}
	return (0);
}

void	case_cmd_rdir(char *str, node *n, int idx)
{
	n->left = init_node(n);
	n->left->type = RDIR;
	make_tree(str_cut_back(str, idx - 1), n->left);
	n->right= init_node(n);
	n->right->type = SCMD;
	n->right->node_str = str_cut_front(str, idx);
}

void	case_rdir_cmd(char *str, node *n, int idx)
{
	int	check;

	check = 0;
	while (str[++idx])
	{
		if (check == 0 && !strchr("<> ", str[idx]))
			check = 1;
		else if (check == 1 && strchr("<>", str[idx]))
			check = 0;
		else if (check == 1 && !strchr("<> ", str[idx]))
		{
			n->left = init_node(n);
			n->left->type = RDIR;
			make_tree(str_cut_front(str, idx), n->left);
			n->right= init_node(n);
			n->right->type = CMD;
			make_tree(str_cut_back(str, idx - 1), n->right);
		}
	}
}

void	case_scmd(char *str, node *n)
{
	n->right= init_node(n);
	n->right->type = SCMD;
	n->right->node_str = strdup(str);
}

int	case_rdir(char *str, node *n, int idx)
{
	if (n->type == RDIR && strchr("<>", str[idx]))
	{
		while (str[++idx])
		{
			if (strchr("<>", str[idx]) && str[idx] != str[idx - 1])
			{
				n->type = RDIRS;
				n->left = init_node(n);
				n->left->type = RDIR;
				make_tree(str_cut_front(str, idx + 1), n->left);
				n->right= init_node(n);
				n->right->type = RDIR;
				make_tree(str_cut_back(str, idx - 1), n->right);
			}
		}
		return (1);
	}
	return (0);
}
