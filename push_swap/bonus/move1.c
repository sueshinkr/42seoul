/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:11:25 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 19:38:22 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_stack(t_list *list, int n)
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
		new->prev = list->tail->next;
		new->next = list->head->next;
		list->head->next->prev = new;
		list->tail->next->next = new;
		list->head->next = new;
	}
	list->count++;
}

void	pop_stack(t_list *list)
{
	t_node	*temp;

	temp = list->head->next;
	if (list->count == 1)
	{
		list->head->next = NULL;
		list->tail->next = NULL;
	}
	else
	{
		list->head->next = list->head->next->next;
		list->head->next->prev = list->tail->next;
		list->tail->next->next = list->head->next;
	}
	free(temp);
	list->count--;
}

void	func_sa(t_list *a)
{
	int	up;
	int	down;

	if (a->count < 2)
		return ;
	up = a->head->next->num;
	down = a->head->next->next->num;
	pop_stack(a);
	pop_stack(a);
	push_stack(a, up);
	push_stack(a, down);
}

void	func_sb(t_list *b)
{
	int	up;
	int	down;

	if (b->count < 2)
		return ;
	up = b->head->next->num;
	down = b->head->next->next->num;
	pop_stack(b);
	pop_stack(b);
	push_stack(b, up);
	push_stack(b, down);
}

void	func_ra(t_list *a)
{
	if (a->count > 1)
	{
		a->tail->next = a->head->next;
		a->head->next = a->head->next->next;
	}
}
