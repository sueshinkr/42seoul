/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:29:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 13:29:40 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	func_ra_sa_rra(t_list *a, t_cmlist *comm)
{
	func_ra(a, comm);
	func_sa(a, comm);
	func_rra(a, comm);
}

void	sort_three(t_list *a, t_cmlist *comm)
{
	t_node	*top;

	top = a->head->next;
	if (top->num > top->next->num && top->num > top->next->next->num)
	{
		func_sa(a, comm);
		func_ra_sa_rra(a, comm);
		if (a->head->next->num > a->head->next->next->num)
			func_sa(a, comm);
	}
	else if (top->num < top->next->num && top->num < top->next->next->num)
	{
		if (top->next->num > top->next->next->num)
			func_ra_sa_rra(a, comm);
	}
	else if (top->num > top->next->num)
		func_sa(a, comm);
	else
	{
		func_ra_sa_rra(a, comm);
		func_sa(a, comm);
	}
}

void	sort_three_reverse_case1(t_list *a, t_list *b, t_cmlist *comm)
{
	func_pa(a, b, comm);
	if (b->head->next->num < b->head->next->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_sa(a, comm);
	func_pa(a, b, comm);
	func_sa(a, comm);
}

void	sort_three_reverse_case2(t_list *a, t_list *b, t_cmlist *comm)
{
	func_pa(a, b, comm);
	if (b->head->next->num < b->head->next->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
}

void	sort_three_reverse(t_list *a, t_list *b, t_cmlist *comm)
{
	t_node	*top;

	top = b->head->next;
	if (top->num < top->next->num && top->num < top->next->next->num)
		sort_three_reverse_case1(a, b, comm);
	else if (top->num > top->next->num && top->num > top->next->next->num)
		sort_three_reverse_case2(a, b, comm);
	else if (top->num < top->next->num)
	{
		func_sb(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else
	{
		func_pa(a, b, comm);
		func_sb(b, comm);
		func_pa(a, b, comm);
		func_sa(a, comm);
		func_pa(a, b, comm);
	}
}
