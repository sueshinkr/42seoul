/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:11:17 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/13 17:03:24 by sueshin          ###   ########.fr       */
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
	while (++idx < list->count)
	{
		temp = temp->next;
		printf("idx %d : %d\n", idx, temp->num);
	}
}
