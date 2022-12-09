/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_case_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:41 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:27:14 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	case_pipe(t_data *data, char *str, t_node *n, int idx)
{
	char	*temp_front;
	char	*temp_back;

	if (str[idx] == '|')
	{
		data->pipe_num++;
		n->type = _pipe;
		temp_front = str_cut_front(str, idx);
		temp_back = str_cut_back(str, idx);
		if (temp_front)
		{
			n->left = init_node();
			n->left->type = _cmd;
			make_tree(data, temp_front, n->left);
		}
		if (temp_back)
		{
			n->right = init_node();
			make_tree(data, temp_back, n->right);
		}
		if (!temp_front || !temp_back)
			data->err_flag = 1;
		return (1);
	}
	return (0);
}
