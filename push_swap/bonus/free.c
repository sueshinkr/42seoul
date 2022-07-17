/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:56:37 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:23:18 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
