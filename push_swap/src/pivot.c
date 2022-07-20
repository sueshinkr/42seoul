/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:11:17 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 15:35:20 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(const void *a, const void *b)
{
	int	num1;
	int	num2;

	num1 = *(int *)a;
	num2 = *(int *)b;
	return (num1 - num2);
}

int	find_pivot_top(t_list *list, int count)
{
	t_node	*temp;
	int		*arr;
	int		idx;
	int		pivot;

	temp = list->head->next;
	arr = (int *)malloc(count * sizeof(int));
	idx = -1;
	while (++idx < count)
	{
		arr[idx] = temp->num;
		temp = temp->next;
	}
	qsort(arr, count, sizeof(int), compare);
	if (count % 2 == 0)
		pivot = arr[count / 2 - 1];
	else
		pivot = arr[count / 2];
	free(arr);
	return (pivot);
}

int	find_pivot_bottom(t_list *list, int count)
{
	t_node	*temp;
	int		*arr;
	int		idx;
	int		pivot;

	temp = list->tail->next;
	arr = (int *)malloc(count * sizeof(int));
	idx = -1;
	while (++idx < count)
	{
		arr[idx] = temp->num;
		temp = temp->prev;
	}
	qsort(arr, count, sizeof(int), compare);
	if (count % 2 == 0)
		pivot = arr[count / 2 - 1];
	else
		pivot = arr[count / 2];
	free(arr);
	return (pivot);
}
