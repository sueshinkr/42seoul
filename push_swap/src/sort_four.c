/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:28:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:33:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	func_papa(t_list *a, t_list *b, t_cmlist *comm)
{
	func_pa(a, b, comm);
	func_pa(a, b, comm);
}

static void	sort_four_last(t_list *a, t_list *b, t_cmlist *comm, int idx)
{
	while (idx++ < 1)
		func_rra(a, comm);
	if (a->head->next->num > a->head->next->next->num)
		func_sa(a, comm);
	if (b->head->next->num < b->head->next->next->num)
		func_sb(b, comm);
	func_papa(a, b, comm);
}

void	sort_four(t_list *a, t_list *b, t_cmlist *comm, int flag)
{
	int	idx;
	int	min1;
	int	min2;

	idx = 4;
	check_min2(a, &min1, &min2);
	while (idx-- > 0 && flag < 2)
	{
		if (a->head->next->num == min1 || a->head->next->num == min2)
		{
			func_pb(b, a, comm);
			flag++;
		}
		else if (a->head->next->next->num == min1
			|| a->head->next->next->num == min2)
		{
			func_sa(a, comm);
			func_pb(b, a, comm);
			flag++;
		}
		else
			func_ra(a, comm);
	}
	sort_four_last(a, b, comm, idx);
}

static void	sort_four_rev_last(t_list *a, t_list *b, t_cmlist *comm, int idx)
{
	while (idx++ < 1)
		func_rrb(b, comm);
	if (b->head->next->num < b->head->next->next->num)
		func_sb(b, comm);
	if (a->head->next->num > a->head->next->next->num)
		func_sa(a, comm);
	func_papa(a, b, comm);
}

void	sort_four_reverse(t_list *a, t_list *b, t_cmlist *comm, int flag)
{
	int	idx;
	int	max1;
	int	max2;

	idx = 4;
	check_max(b, &max1, &max2);
	while (idx-- > 0 && flag < 2)
	{
		if (b->head->next->num == max1 || b->head->next->num == max2)
		{
			func_pa(a, b, comm);
			flag++;
		}
		else if (b->head->next->next->num == max1
			|| b->head->next->next->num == max2)
		{
			func_sb(b, comm);
			func_pa(a, b, comm);
			flag++;
		}
		else
			func_rb(b, comm);
	}
	sort_four_rev_last(a, b, comm, idx);
}
