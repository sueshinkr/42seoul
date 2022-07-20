/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:36:03 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 20:05:24 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_command(t_cmlist *list, char *str)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	new->comm = ft_strdup(str);
	new->next = NULL;
	if (!list->head->next)
	{
		list->head->next = new;
		list->tail->next = new;
	}
	else
	{
		list->tail->next->next = new;
		list->tail->next = new;
	}
}

static t_command	*check_ss(t_command *temp)
{
	if ((temp->comm[1] == 'a' && temp->next->comm[1] == 'b')
		|| (temp->comm[1] == 'b' && temp->next->comm[1] == 'a'))
		ft_printf("ss\n");
	else
	{
		ft_printf("%s", temp->comm);
		ft_printf("%s", temp->next->comm);
	}
	temp = temp->next;
	return (temp);
}

static t_command	*check_rrr(t_command *temp)
{
	if ((temp->comm[2] == 'a' && temp->next->comm[2] == 'b')
		|| (temp->comm[2] == 'b' && temp->next->comm[2] == 'a'))
		ft_printf("rrr\n");
	else
	{
		ft_printf("%s", temp->comm);
		ft_printf("%s", temp->next->comm);
	}
	temp = temp->next;
	return (temp);
}

static t_command	*check_rr(t_command *temp)
{
	if ((temp->comm[1] == 'a' && temp->next->comm[1] == 'b')
		|| (temp->comm[1] == 'b' && temp->next->comm[1] == 'a'))
		ft_printf("rr\n");
	else
	{
		ft_printf("%s", temp->comm);
		ft_printf("%s", temp->next->comm);
	}
	temp = temp->next;
	return (temp);
}

void	print_command(t_cmlist *list)
{
	t_command	*temp;

	temp = list->head;
	while (temp->next)
	{
		temp = temp->next;
		if (!temp->next)
			ft_printf("%s", temp->comm);
		else if (temp->comm[0] == 's' && temp->next->comm[0] == 's')
			temp = check_ss(temp);
		else if (temp->comm[1] == 'r' && temp->next->comm[1] == 'r')
			temp = check_rrr(temp);
		else if (temp->comm[0] == 'r' && temp->next->comm[0] == 'r')
			temp = check_rr(temp);
		else
			ft_printf("%s", temp->comm);
	}
	free_command(list);
}
