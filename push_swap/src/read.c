/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:35:03 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:46:25 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_atoi(const char	*str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else
			print_error();
		str++;
	}
	if (result > INT_MAX || result < INT_MIN)
		print_error();
	return (sign * result);
}

static void	check_dup(t_list *list, int flag)
{
	t_node	*temp;
	int		*arr;
	int		idx;

	temp = list->head->next;
	arr = (int *)malloc(list->count * sizeof(int));
	if (!arr)
		exit(1);
	idx = -1;
	while (++idx < list->count)
	{
		if (idx < list->count - 1 && temp->num > temp->next->num)
			flag = 0;
		arr[idx] = temp->num;
		temp = temp->next;
	}
	ft_qsort(arr, 0, list->count - 1);
	while (--idx > 0)
	{
		if (arr[idx] == arr[idx - 1])
			print_error();
	}
	if (flag == 1)
		exit(0);
	free(arr);
}

void	read_arg(t_list *a, int argc, char **argv)
{
	int			idx;
	char		**arr;

	if (argc == 2)
	{
		idx = -1;
		arr = ft_split(argv[1], ' ');
		if (!arr)
			exit(1);
		while (arr[++idx])
		{
			init_stack(a, ft_atoi(arr[idx]));
			free(arr[idx]);
		}
		free(arr);
	}
	else
	{
		idx = 0;
		while (argv[++idx])
			init_stack(a, ft_atoi(argv[idx]));
	}
	check_dup(a, 1);
}
