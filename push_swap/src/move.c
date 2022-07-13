/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:11:25 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/13 17:09:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	func_sa(t_list *a, t_cmlist *comm)
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
	save_command(comm, "sa\n");
}

void	func_sb(t_list *b, t_cmlist *comm)
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
	save_command(comm, "sb\n");
}

void	func_ra(t_list *a, t_cmlist *comm)
{
	if (a->count > 1)
	{
		a->tail->next = a->head->next;
		a->head->next = a->head->next->next;
	}
	save_command(comm, "ra\n");
}

void	func_rb(t_list *b, t_cmlist *comm)
{
	if (b->count > 1)
	{
		b->tail->next = b->head->next;
		b->head->next = b->head->next->next;
	}
	save_command(comm, "rb\n");
}

void	func_rra(t_list *a, t_cmlist *comm)
{
	if (a->count > 1)
	{
		a->head->next = a->tail->next;
		a->tail->next = a->tail->next->prev;
	}
	save_command(comm, "rra\n");
}

void	func_rrb(t_list *b, t_cmlist *comm)
{
	if (b->count > 1)
	{
		b->head->next = b->tail->next;
		b->tail->next = b->tail->next->prev;
	}
	save_command(comm, "rrb\n");
}

void	func_pa(t_list *a, t_list *b, t_cmlist *comm)
{
	if (b->count < 1)
		return ;
	push_stack(a, b->head->next->num);
	pop_stack(b);
	save_command(comm, "pa\n");
}

void	func_pb(t_list *b, t_list *a, t_cmlist *comm)
{
	if (a->count < 1)
		return ;
	push_stack(b, a->head->next->num);
	pop_stack(a);
	save_command(comm, "pb\n");
}