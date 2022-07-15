/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:11:17 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/14 16:11:33 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char	*str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
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
			break ;
		str++;
	}
	if (result > LONG_MAX)
		return (-1 + (sign < 0));
	return (sign * (int)result);
}

void	check_minmax(t_list *list, int *max, int *min)
{
	t_node	*temp;
	int	idx;

	temp = list->head->next;
	idx = 5;
	*max = INT_MIN;
	*min = INT_MAX;
	while(idx-- > 0)
	{
		if (temp->num > *max)
			*max = temp->num;
		if (temp->num < *min)
			*min = temp->num;
		temp = temp->next;
	}
}

void	save_command(t_cmlist *list, char *str)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	new->comm = ft_strdup(str);
	if (!list->head->next)
	{
		list->head->next = new;
		list->tail->next = new;
	}
	else
	{
		list->tail->next->next = new;
		list->tail->next = new;
		new->next = NULL;
	}
}

void	print_command(t_cmlist *list)
{
	t_command	*temp;

	temp = list->head;
	while (temp->next)
	{
		temp = temp->next;
		if (!temp->next)
			ft_printf("%s", temp->comm);
		else if (ft_strncmp(temp->comm, "sa\n", 10) == 0
			|| ft_strncmp(temp->comm, "sb\n", 10) == 0)
		{
			if (ft_strncmp(temp->next->comm, "sa\n", 10) == 0
				|| ft_strncmp(temp->next->comm, "sb\n", 10) == 0)
			{
				ft_printf("ss\n");
				temp = temp->next;
			}
			else
				ft_printf("%s", temp->comm);
		}
		else if (ft_strncmp(temp->comm, "ra\n", 10) == 0
			&& ft_strncmp(temp->next->comm, "rb\n", 10) == 0)
		{
			ft_printf("rr\n");
			temp = temp->next;
		}
		else if (ft_strncmp(temp->comm, "rb\n", 10) == 0
			&& ft_strncmp(temp->next->comm, "ra\n", 10) == 0)
		{
			ft_printf("rr\n");
			temp = temp->next;
		}
		else if (ft_strncmp(temp->comm, "rra\n", 10) == 0
			&& ft_strncmp(temp->next->comm, "rrb\n", 10) == 0)
		{
			ft_printf("rrr\n");
			temp = temp->next;
		}
		else if (ft_strncmp(temp->comm, "rrb\n", 10) == 0
			&& ft_strncmp(temp->next->comm, "rra\n", 10) == 0)
		{
				ft_printf("rrr\n");
				temp = temp->next;
		}
		else
			ft_printf("%s", temp->comm);
	}
}

void	node_print(t_list *list)
{
	int		idx;
	t_node	*temp;

	idx = -1;
	temp = list->head;
	printf("**********\n");
	while (++idx < list->count)
	{
		temp = temp->next;
		printf("idx %d : %d\n", idx, temp->num);
	}
	printf("**********\n");
}

static int	compare(const void *a, const void *b)
{
	int	num1;
	int	num2;

	num1 = *(int *)a;
	num2 = *(int *)b;
	return (num1 - num2);
}

int	find_pivot(t_list *list, int count)
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

void	read_arg(t_list *a, int argc, char **argv)
{
	int		idx;
	char	**arr;

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
}

int	find_maxidx(t_list *a, int pivot, int count)
{
	t_node	*temp;
	int	idx;
	int	max;

	temp = a->head->next;
	idx = -1;
	while (++idx < count)
	{
		if (temp->num <= pivot)
			max = idx;
		temp = temp->next;
	}
	return (max + 1);
}

int	check_arr(t_list *a, int count)
{
	t_node	*temp;
	int	idx;

	temp = a->head;
	idx = -1;
	while (++idx < count - 1)
	{
		temp = temp->next;
		if (temp->num > temp->next->num)
			return (0);
	}
	return (1);
}