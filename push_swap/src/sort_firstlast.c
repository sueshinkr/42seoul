/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_firstlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:32:58 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:32:58 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_recur_atob_2nd(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	ra;

	if (count <= 1)
		return ;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three_only(a, comm);
	else if (count == 4)
		sort_four_only(a, b, comm);
	else if (a->count == 5)
		sort_five_only(a, b, comm);
	else
	{
		ra = devide_rapb(a, b, comm, count);
		sort_recur_atob_2nd(a, b, comm, ra);
		sort_select_btoa(a, b, comm, count - ra);
	}
}

void	sort_recur_atob_first(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	ra;

	if (count <= 1)
		return ;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three_only(a, comm);
	else if (count == 4)
		sort_four_only(a, b, comm);
	else if (a->count == 5)
		sort_five_only(a, b, comm);
	else
	{
		ra = devide_rapb(a, b, comm, count);
		sort_recur_atob_2nd(a, b, comm, ra);
		sort_recur_btoa_last(a, b, comm, count - ra);
	}
}

void	sort_recur_btoa_last(t_list *a, t_list *b, t_cmlist *comm, int count)
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
		sort_three_reverse_only(a, b, comm);
	else if (count == 4)
		sort_four_reverse_only(a, b, comm);
	else
	{
		rb = devide_rbpa(a, b, comm, count);
		sort_select_atob(a, b, comm, count - rb);
		sort_recur_btoa_last(a, b, comm, rb);
	}
}
