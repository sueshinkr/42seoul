/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:36:40 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:39:01 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*str1_unchar;
	unsigned char	*str2_unchar;

	str1_unchar = (unsigned char *)str1;
	str2_unchar = (unsigned char *)str2;
	while (*str1_unchar || *str2_unchar)
	{
		if (*str1_unchar != *str2_unchar)
			return (*str1_unchar - *str2_unchar);
		str1_unchar++;
		str2_unchar++;
	}
	return (0);
}

void	select_move_orerror(char *str, t_list *a, t_list *b)
{
	if (!ft_strcmp(str, "rra\n"))
		func_rra(a);
	else if (!ft_strcmp(str, "rrb\n"))
		func_rrb(b);
	else if (!ft_strcmp(str, "rrr\n"))
	{
		func_rra(a);
		func_rrb(b);
	}
	else if (!ft_strcmp(str, "pa\n"))
		func_pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		func_pb(b, a);
	else
	{
		ft_printf("Error\n");
		exit(0);
	}
}

void	select_move(char *str, t_list *a, t_list *b)
{
	if (!ft_strcmp(str, "sa\n"))
		func_sa(a);
	else if (!ft_strcmp(str, "sb\n"))
		func_sb(b);
	else if (!ft_strcmp(str, "ss\n"))
	{
		func_sa(a);
		func_sb(b);
	}
	else if (!ft_strcmp(str, "ra\n"))
		func_ra(a);
	else if (!ft_strcmp(str, "rb\n"))
		func_rb(b);
	else if (!ft_strcmp(str, "rr\n"))
	{
		func_ra(a);
		func_rb(b);
	}
	else
		select_move_orerror(str, a, b);
}
