/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_only.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:33:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 14:23:13 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list *list, t_cmlist *comm)
{
	if (list->head->next->num > list->head->next->next->num)
		func_sa(list, comm);
}

void	sort_three_only(t_list *a, t_cmlist *comm)
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
			func_sa(a, comm);
			func_ra(a, comm);
		}
	}
	else if (top->num > top->next->num)
		func_sa(a, comm);
	else
		func_rra(a, comm);
}

void	sort_three_reverse_only(t_list *b, t_cmlist *comm)
{
	t_node	*top;

	top = b->head->next;
	if (top->num < top->next->num && top->num < top->next->next->num)
	{
		func_rb(b, comm);
		if (top->next->num < top->next->next->num)
			func_sb(b, comm);
	}
	else if (top->num < top->next->num && top->num > top->next->next->num)
	{
		if (top->next->num < top->next->next->num)
		{
			func_sb(b, comm);
			func_rb(b, comm);
		}
	}
	else if (top->num < top->next->num)
		func_sb(b, comm);
	else
		func_rrb(b, comm);
}

void	sort_four_only(t_list *a, t_list *b, t_cmlist *comm)
{
	int	idx;
	int	min;

	idx = 4;
	check_min(a, &min);
	while (idx-- > 0)
	{
		if (a->head->next->num == min)
			func_pb(b, a, comm);
		else
			func_ra(a, comm);
	}
	sort_three_only(a, comm);
	func_pa(a, b, comm);
}

void	sort_five_only(t_list *a, t_list *b, t_cmlist *comm)
{
	int	idx;
	int	max;
	int	min;
	int	flag;

	idx = 5;
	flag = 0;
	check_minmax(a, &max, &min);
	while (idx-- > 0 && flag < 2)
	{
		if (a->head->next->num == max || a->head->next->num == min)
		{
			func_pb(b, a, comm);
			flag++;
		}
		else
			func_ra(a, comm);
	}
	sort_three_only(a, comm);
	if (b->head->next->num > b->tail->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
	func_ra(a, comm);
}
