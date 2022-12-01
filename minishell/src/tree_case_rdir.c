#include "minishell.h"

static void	case_rdir_cmd_separate(t_data *data, char *str, t_node *n, int idx)
{
	n->left = init_node();
	n->left->type = RDIR;
	make_tree(data, str_cut_front(str, idx + 1), n->left);
	n->right = init_node();
	n->right->type = CMD;
	make_tree(data, str_cut_back(str, idx - 1), n->right);
}

static void	case_rdir_only(t_data *data, char *str, t_node *n, int idx)
{
	n->left = init_node();
	n->left->type = RDIR;
	make_tree(data, str_cut_front(str, idx + 1), n->left);
}

void	case_rdir_cmd(t_data *data, char *str, t_node *n, int idx)
{
	int	check;

	check = 0;
	while (str[++idx])
	{
		if (check == 0 && ft_strchr("<> ", str[idx]))
			;
		else if (check == 0 && !ft_strchr("<> ", str[idx]))
			check = 1;
		else if (check == 1 && ft_strchr("<>", str[idx]))
			check = 0;
		else if (check == 1 && str[idx] == ' ')
		{
			if (!str[idx + 1])
				break ;
			else if (ft_strchr("<>", str[idx + 1]))
				check = 0;
			else
			{
				case_rdir_cmd_separate(data, str, n, idx);
				return ;
			}
		}
	}
	case_rdir_only(data, str, n, idx);
}

int	case_rdir(t_data *data, char *str, t_node *n, int idx)
{
	if (n->type == RDIR && ft_strchr("<>", str[idx]))
	{
		while (str[++idx])
		{
			if (ft_strchr("<>", str[idx]) && str[idx] != str[idx - 1])
			{
				n->type = RDIRS;
				n->left = init_node();
				n->left->type = RDIR;
				make_tree(data, str_cut_front(str, idx + 1), n->left);
				n->right = init_node();
				n->right->type = RDIR;
				make_tree(data, str_cut_back(str, idx - 1), n->right);
				return (1);
			}
		}
		return (1);
	}
	return (0);
}
