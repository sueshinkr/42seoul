/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:36:40 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:23:20 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
