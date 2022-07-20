/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:59:13 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:33:15 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	devide_rrbpa(t_list *a, t_list *b, t_cm *comm, int count)
{
	int	pivot;
	int	rb;

	pivot = find_pivot_bottom(b, count);
	rb = 0;
	while (count-- > 0)
	{
		func_rrb(b, comm);
		if (b->head->next->num <= pivot)
			rb++;
		else
			func_pa(a, b, comm);
	}
	return (rb);
}

void	sort_recur_btoa_top(t_list *a, t_list *b, t_cm *comm, int count)
{
	int	rb;

	if (count == 1)
		func_pa(a, b, comm);
	else if (count == 2)
	{
		if (b->head->next->num < b->head->next->next->num)
			func_sb(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else if (count == 3)
		sort_three_reverse(a, b, comm);
	else if (count == 4)
		sort_four_reverse(a, b, comm, 0);
	else
	{
		rb = devide_rbpa(a, b, comm, count);
		sort_select_atob(a, b, comm, count - rb);
		sort_select_btoa(a, b, comm, -rb);
	}
}

void	sort_recur_btoa_bottom(t_list *a, t_list *b, t_cm *comm, int count)
{
	int	rb;

	if (count == 1)
	{
		func_rrb(b, comm);
		func_pa(a, b, comm);
	}
	else
	{
		rb = devide_rrbpa(a, b, comm, count);
		sort_select_atob(a, b, comm, count - rb);
		sort_select_btoa(a, b, comm, rb);
	}
}
