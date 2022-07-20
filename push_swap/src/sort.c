/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:22:43 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 11:23:13 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list *list, t_cmlist *comm)
{
	if (list->head->next > list->head->next->next)
		func_sa(list, comm);
}

void	sort_three(t_list *a, t_cmlist *comm)
{
	t_node	*top;

	top = a->head->next;
	if (top->num > top->next->num && top->num > top->next->next->num)
	{
		func_ra(a, comm);
		if (top->next->num > top->next->next->num)
			func_sa(a, comm);
	}
	else if (top->num < top->next->num && top->num < top->next->next->num)
	{
		if (top->next->num > top->next->next->num)
		{
			func_ra(a, comm);
			func_sa(a, comm);
			func_rra(a, comm);
		}
	}
	else if (top->num > top->next->num)
		func_sa(a, comm);
	else
		func_rra(a, comm);
}

void	sort_five(t_list *a, t_list *b, t_cmlist *comm)
{
	t_node	*top;
	t_node	*temp;
	int		idx;
	int		max;
	int		min;

	top = a->head->next;
	temp = top;
	idx = 5;
	check_minmax(a, &max, &min);
	while (idx-- > 0)
	{
		if (a->head->next->num == max || a->head->next->num == min)
			func_pb(b, a, comm);
		else
			func_ra(a, comm);
	}
	sort_three(a, comm);
	if (b->head->next->num > b->tail->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
	func_ra(a, comm);
}
