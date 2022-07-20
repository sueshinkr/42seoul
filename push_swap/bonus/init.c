/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:42:17 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:40:36 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*init_stack_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		exit(1);
	list->head = malloc(sizeof(t_node));
	if (!list->head)
		exit(1);
	list->tail = malloc(sizeof(t_node));
	if (!list->tail)
		exit(1);
	list->head->next = NULL;
	list->tail->prev = NULL;
	list->count = 0;
	return (list);
}

void	init_stack(t_list *list, int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->num = n;
	if (!list->head->next)
	{
		list->head->next = new;
		list->tail->next = new;
	}
	else
	{
		new->next = list->head->next;
		new->prev = list->tail->next;
		list->head->next->prev = new;
		list->tail->next->next = new;
		list->tail->next = new;
	}
	list->count++;
}
