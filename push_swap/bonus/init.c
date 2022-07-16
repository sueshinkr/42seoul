/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:42:17 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 16:34:57 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_list(t_list *a, t_list *b)
{
	a->head = malloc(sizeof(t_node));
	a->head->next = NULL;
	a->tail = malloc(sizeof(t_node));
	a->tail->prev = NULL;
	b->head = malloc(sizeof(t_node));
	b->head->next = NULL;
	b->tail = malloc(sizeof(t_node));
	b->tail->prev = NULL;
	a->count = 0;
	b->count = 0;
}

void	init_stack(t_list *list, int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
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
