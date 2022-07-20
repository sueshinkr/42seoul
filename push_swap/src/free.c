/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:05:15 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 16:27:36 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_list *list)
{
	t_node	*cur;
	t_node	*del;

	cur = list->head->next;
	del = list->head->next;
	while (list->count-- > 0)
	{
		cur = cur->next;
		free(del);
		del = cur;
	}
}

void	free_list(t_list *list)
{
	free_stack(list);
	free(list->head);
	free(list->tail);
	free(list);
}

static void	free_comm(t_cmlist *list)
{
	t_command	*cur;
	t_command	*del;

	cur = list->head->next;
	del = list->head->next;
	while (cur)
	{
		free(del->comm);
		cur = cur->next;
		free(del);
		del = cur;
	}
}

void	free_command(t_cmlist *list)
{
	free_comm(list);
	free(list->head);
	free(list->tail);
	free(list);
}
