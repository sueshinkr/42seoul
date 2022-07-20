/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:33:29 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 02:14:46 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_min(t_list *list, int *min)
{
	t_node	*temp;
	int		idx;

	temp = list->head->next;
	idx = 4;
	*min = INT_MAX;
	while (idx-- > 0)
	{
		if (temp->num < *min)
			*min = temp->num;
		temp = temp->next;
	}
}

void	check_min2(t_list *list, int *min1, int *min2)
{
	t_node	*temp;
	int		idx;

	temp = list->head->next;
	idx = 4;
	*min1 = INT_MAX - 1;
	*min2 = INT_MAX;
	while (idx-- > 0)
	{
		if (temp->num < *min1)
		{
			*min2 = *min1;
			*min1 = temp->num;
		}
		else if (temp->num < *min2)
			*min2 = temp->num;
		temp = temp->next;
	}
}

void	check_max(t_list *list, int *max1, int *max2)
{
	t_node	*temp;
	int		idx;

	temp = list->head->next;
	idx = 4;
	*max1 = INT_MIN + 1;
	*max2 = INT_MIN;
	while (idx-- > 0)
	{
		if (temp->num > *max1)
		{
			*max2 = *max1;
			*max1 = temp->num;
		}
		else if (temp->num > *max2)
			*max2 = temp->num;
		temp = temp->next;
	}
}

void	check_minmax(t_list *list, int *max, int *min)
{
	t_node	*temp;
	int		idx;

	temp = list->head->next;
	idx = 5;
	*max = INT_MIN;
	*min = INT_MAX;
	while (idx-- > 0)
	{
		if (temp->num > *max)
			*max = temp->num;
		if (temp->num < *min)
			*min = temp->num;
		temp = temp->next;
	}
}
