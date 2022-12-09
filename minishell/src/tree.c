/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:44 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 16:14:45 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*init_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->type = _word;
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
	if (n->type == _word)
	{
		n->type = _cmd;
		make_tree(data, str, n);
	}
}

void	search_tree(t_data *data, t_node *n)
{
	if (n->left)
		search_tree(data, n->left);
	if (n->right)
		search_tree(data, n->right);
	if (n->type == _pipe)
		;
	else if (n->type == _rdir)
	{
		if (!data->err_flag)
			set_rdir(data, n);
	}
	else if (n->type == _scmd)
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
	if (data->err_flag != 1)
		search_tree(data, head);
	else
	{
		data->exit_code = 1;
		write(2, "Syntax Error\n", ft_strlen("Syntax Error\n"));
	}
	if (data->pid)
	{
		waitpid(data->pid, &data->exit_code, 0);
		data->exit_code = data->exit_code >> 8;
	}
	while (wait(0) != -1)
		;
	reset_data(data);
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
