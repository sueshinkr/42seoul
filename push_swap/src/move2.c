/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:41:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 14:42:44 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
