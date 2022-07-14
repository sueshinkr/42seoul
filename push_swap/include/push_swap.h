/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:10:40 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/13 16:46:01 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_command
{
	char				*comm;
	struct s_command	*next;
} t_command;

typedef struct s_cmlist
{
	t_command	*head;
	t_command	*tail;
} t_cmlist;

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_list;

void	init_stack(t_list *list, int n);
void	push_stack(t_list *list, int n);

void	func_sa(t_list *a, t_cmlist *comm);
void	func_ra(t_list *a, t_cmlist *comm);
void	func_rra(t_list *a, t_cmlist *comm);
void	func_pa(t_list *a, t_list *b, t_cmlist *comm);
void	func_sb(t_list *b, t_cmlist *comm);
void	func_rb(t_list *b, t_cmlist *comm);
void	func_rrb(t_list *b, t_cmlist *comm);
void	func_pb(t_list *b, t_list *a, t_cmlist *comm);


int		ft_atoi(const char	*str);
void	check_minmax(t_list *list, int *max, int *min);
void	node_print(t_list *list);
void	save_command(t_cmlist *list, char *str);
void	print_command(t_cmlist *list);

void	sort_two(t_list *list, t_cmlist *comm);
void	sort_three(t_list *list, t_cmlist *comm);
void	sort_five(t_list *a, t_list *b, t_cmlist *comm);

#endif