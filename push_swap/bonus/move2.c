/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:41:30 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 19:38:24 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	func_rb(t_list *b)
{
	if (b->count > 1)
	{
		b->tail->next = b->head->next;
		b->head->next = b->head->next->next;
	}
}

void	func_rra(t_list *a)
{
	if (a->count > 1)
	{
		a->head->next = a->tail->next;
		a->tail->next = a->tail->next->prev;
	}
}

void	func_rrb(t_list *b)
{
	if (b->count > 1)
	{
		b->head->next = b->tail->next;
		b->tail->next = b->tail->next->prev;
	}
}

void	func_pa(t_list *a, t_list *b)
{
	if (b->count < 1)
		return ;
	push_stack(a, b->head->next->num);
	pop_stack(b);
}

void	func_pb(t_list *b, t_list *a)
{
	if (a->count < 1)
		return ;
	push_stack(b, a->head->next->num);
	pop_stack(a);
}
