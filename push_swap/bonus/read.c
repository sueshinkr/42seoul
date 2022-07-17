/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:35:03 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 19:14:37 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(2);
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

static int	compare(const void *a, const void *b)
{
	int	num1;
	int	num2;

	num1 = *(int *)a;
	num2 = *(int *)b;
	return (num1 - num2);
}

int	check_dup(t_list *list)
{
	t_node	*temp;
	int		*arr;
	int		idx;
	int		flag;

	temp = list->head->next;
	flag = 1;
	arr = (int *)malloc(list->count * sizeof(int));
	idx = -1;
	while (++idx < list->count)
	{
		if (idx < list->count - 1 && temp->num > temp->next->num)
			flag = 0;
		arr[idx] = temp->num;
		temp = temp->next;
	}
	qsort(arr, list->count, sizeof(int), compare);
	while (--idx > 0)
	{
		if (arr[idx] == arr[idx - 1])
			print_error();
	}
	if (flag == 1)
		return (1);
	return (0);
}

void	read_arg(t_list *a, int argc, char **argv)
{
	int			idx;
	char		**arr;

	if (argc == 2)
	{
		idx = -1;
		arr = ft_split(argv[1], ' ');
		while (arr[++idx])
			init_stack(a, ft_atoi(arr[idx]));
	}
	else
	{
		idx = 0;
		while (argv[++idx])
			init_stack(a, ft_atoi(argv[idx]));
	}
	//check_dup(a);
}
