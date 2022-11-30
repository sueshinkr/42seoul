#include "minishell.h"

static void	case_scmd(char *str, t_node *n)
{
	n->right = init_node();
	n->right->type = SCMD;
	n->right->node_str = ft_strdup(str);
}

static void	case_cmd_rdir(t_data *data, char *str, t_node *n, int idx)
{
	n->left = init_node();
	n->left->type = RDIR;
	make_tree(data, str_cut_back(str, idx - 1), n->left);
	n->right = init_node();
	n->right->type = SCMD;
	n->right->node_str = str_cut_front(str, idx);
}

int	case_cmd(t_data *data, char *str, t_node *n, int idx)
{
	if (n->type == CMD && ft_strchr("<>", str[idx]))
	{
		case_rdir_cmd(data, str, n, idx - 1);
		return (1);
	}
	if (n->type == CMD && !ft_strchr("<> ", str[idx]))
	{
		while (str[++idx])
		{
			if (ft_strchr("<>", str[idx]) && str[idx - 1] != -1)
			{
				case_cmd_rdir(data, str, n, idx);
				return (1);
			}
		}
		case_scmd(str, n);
		return (1);
	}
	return (0);
}
