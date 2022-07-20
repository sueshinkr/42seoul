/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:28:53 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:33:26 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list *list, t_cm *comm)
{
	if (list->head->next->num > list->head->next->next->num)
		func_sa(list, comm);
}

void	sort_select_atob(t_list *a, t_list *b, t_cm *comm, int count)
{
	if (count > 0)
		sort_recur_atob_top(a, b, comm, count);
	else
		sort_recur_atob_bottom(a, b, comm, -count);
}

void	sort_select_btoa(t_list *a, t_list *b, t_cm *comm, int count)
{
	if (count > 0)
		sort_recur_btoa_top(a, b, comm, count);
	else
		sort_recur_btoa_bottom(a, b, comm, -count);
}

int	devide_rapb(t_list *a, t_list *b, t_cm *comm, int count)
{
	int	pivot;
	int	ra;

	pivot = find_pivot_top(a, count);
	ra = 0;
	while (count-- > 0)
	{
		if (a->head->next->num > pivot)
		{
			func_ra(a, comm);
			ra++;
		}
		else
			func_pb(b, a, comm);
	}
	return (ra);
}

int	devide_rbpa(t_list *a, t_list *b, t_cm *comm, int count)
{
	int	pivot;
	int	rb;

	pivot = find_pivot_top(b, count);
	rb = 0;
	while (count-- > 0)
	{
		if (b->head->next->num <= pivot)
		{
			func_rb(b, comm);
			rb++;
		}
		else
			func_pa(a, b, comm);
	}
	return (rb);
}
