/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:59:10 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 14:36:21 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	devide_rrapb(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	ra;

	pivot = find_pivot_bottom(a, count);
	ra = 0;
	while (count-- > 0)
	{
		func_rra(a, comm);
		if (a->head->next->num > pivot)
			ra++;
		else
			func_pb(b, a, comm);
	}
	return (ra);
}

void	sort_recur_atob_top(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	ra;

	if (count <= 1)
		return ;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three(a, comm);
	else if (count == 4)
		sort_four(a, b, comm);
	else
	{
		ra = devide_rapb(a, b, comm, count);
		sort_select_atob(a, b, comm, -ra);
		sort_select_btoa(a, b, comm, count - ra);
	}
}

void	sort_recur_atob_bottom(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	ra;

	if (count <= 1)
		return ;
	else if (count == 2)
	{
		func_rra(a, comm);
		func_rra(a, comm);
		sort_two(a, comm);
	}
	else if (count == 3)
	{
		func_rra(a, comm);
		func_rra(a, comm);
		func_rra(a, comm);
		sort_three(a, comm);
	}
	else
	{
		ra = devide_rrapb(a, b, comm, count);
		sort_select_atob(a, b, comm, ra);
		sort_select_btoa(a, b, comm, count - ra);
	}
}
