#include "minishell.h"

int	case_pipe(t_data *data, char *str, node *n, int idx)
{
	if (str[idx] == '|')
	{
		data->pipe_num++;
		n->type = PIPE;
		n->left = init_node(n);
		n->left->pipe++;
		n->left->type = CMD;
		make_tree(data, str_cut_front(str, idx), n->left);
		n->right= init_node(n);
		make_tree(data, str_cut_back(str, idx), n->right);
		return (1);
	}
	return (0);
}

int	case_cmd(t_data *data, char *str, node *n, int idx)
{
	if (n->type == CMD && strchr("<>", str[idx]))
	{
		case_rdir_cmd(data, str, n, idx);
		return (1);
	}
	if (n->type == CMD && !strchr("<> ", str[idx]))
	{
		while (str[++idx])
		{
			if (strchr("<>", str[idx]) && str[idx - 1] != -1)
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

void	case_cmd_rdir(t_data *data, char *str, node *n, int idx)
{
	n->left = init_node(n);
	n->left->type = RDIR;
	make_tree(data, str_cut_back(str, idx - 1), n->left);
	n->right= init_node(n);
	n->right->type = SCMD;
	n->right->node_str = str_cut_front(str, idx);
}

void	case_rdir_cmd(t_data *data, char *str, node *n, int idx)
{
	// < Makefile cat

	// 처음 <>공백 넘어가고 다음 <>공백 올때까지 읽기
	// 만약 다음 <>가 있으면 거기서부터 다시 시작
	// 아니고 공백이 오면 cmd로 처리

	int	check;

	check = 0;
	while (str[idx])
	{
		if (check == 0 && strchr("<> ", str[idx]))
			idx++;
		else if (check == 0 && !strchr("<> ", str[idx]))
		{
			check = 1;
			idx++;
		}
		else if (check == 1 && strchr("<>", str[idx]))
		{
			check = 0;
			idx++;
		}
		else if (check == 1 && str[idx] == ' ')
		{
			if (str[idx + 1] && strchr("<>", str[idx + 1]))
			{
				check = 0;
				idx++;
			}
			else
			{
				n->left = init_node(n);
				n->left->type = RDIR;
				make_tree(data, str_cut_front(str, idx + 1), n->left);
				n->right= init_node(n);
				n->right->type = CMD;
				make_tree(data, str_cut_back(str, idx - 1), n->right);
				return ;
			}
		}
		else
			idx++;
	}
	n->type = RDIR;
	make_tree(data, str, n);
}

void	case_scmd(char *str, node *n)
{
	n->right= init_node(n);
	n->right->type = SCMD;
	n->right->node_str = strdup(str);
}

int	case_rdir(t_data *data, char *str, node *n, int idx)
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
				make_tree(data, str_cut_front(str, idx + 1), n->left);
				n->right= init_node(n);
				n->right->type = RDIR;
				make_tree(data, str_cut_back(str, idx - 1), n->right);
			}
		}
		return (1);
	}
	return (0);
}
