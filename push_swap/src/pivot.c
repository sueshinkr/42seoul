/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:11:17 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:19:57 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_num(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_qsort(int *data, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot])
			i++;
		while (j > start && data[j] >= data[pivot])
			j--;
		if (i > j)
			swap_num(&data[pivot], &data[j]);
		else
			swap_num(&data[i], &data[j]);
	}
	ft_qsort(data, start, j - 1);
	ft_qsort(data, j + 1, end);
}

int	find_pivot_top(t_list *list, int count)
{
	t_node	*temp;
	int		*arr;
	int		idx;
	int		pivot;

	temp = list->head->next;
	arr = (int *)malloc(count * sizeof(int));
	if (!arr)
		exit(1);
	idx = -1;
	while (++idx < count)
	{
		arr[idx] = temp->num;
		temp = temp->next;
	}
	ft_qsort(arr, 0, count - 1);
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
	if (!arr)
		exit(1);
	idx = -1;
	while (++idx < count)
	{
		arr[idx] = temp->num;
		temp = temp->prev;
	}
	ft_qsort(arr, 0, count - 1);
	if (count % 2 == 0)
		pivot = arr[count / 2 - 1];
	else
		pivot = arr[count / 2];
	free(arr);
	return (pivot);
}
