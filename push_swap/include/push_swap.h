/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:10:40 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:33:06 by sueshin          ###   ########.fr       */
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

void	init_list(t_list *a, t_list *b, t_cmlist *comm);
void	init_stack(t_list *list, int n);
void	read_arg(t_list *a, int argc, char **argv);

void	push_stack(t_list *list, int n);
void	pop_stack(t_list *list);
void	func_sa(t_list *a, t_cmlist *comm);
void	func_ra(t_list *a, t_cmlist *comm);
void	func_rra(t_list *a, t_cmlist *comm);
void	func_pa(t_list *a, t_list *b, t_cmlist *comm);
void	func_sb(t_list *b, t_cmlist *comm);
void	func_rb(t_list *b, t_cmlist *comm);
void	func_rrb(t_list *b, t_cmlist *comm);
void	func_pb(t_list *b, t_list *a, t_cmlist *comm);

void	save_command(t_cmlist *list, char *str);
void	print_command(t_cmlist *list);

void	check_min(t_list *list, int *min);
void	check_min2(t_list *list, int *min1, int *min2);
void	check_max(t_list *list, int *max1, int *max2);
void	check_minmax(t_list *list, int *max, int *min);

int		find_pivot_top(t_list *list, int count);
int		find_pivot_bottom(t_list *list, int count);
char	**ft_split(char const *str, char c);

void	sort_two(t_list *list, t_cmlist *comm);
void	sort_three(t_list *list, t_cmlist *comm);
void	sort_three_reverse(t_list *a, t_list *b, t_cmlist *comm);
void	sort_three_only(t_list *a, t_cmlist *comm);
void	sort_three_reverse_only(t_list *a, t_list *b, t_cmlist *comm);
void	sort_four(t_list *a, t_list *b, t_cmlist *comm, int flag);
void	sort_four_reverse(t_list *a, t_list *b, t_cmlist *comm, int flag);
void	sort_four_only(t_list *a, t_list *b, t_cmlist *comm);
void	sort_four_reverse_only(t_list *a, t_list *b, t_cmlist *comm);
void	sort_five(t_list *a, t_list *b, t_cmlist *comm);
void	sort_five_only(t_list *a, t_list *b, t_cmlist *comm);

void	sort_select_atob(t_list *a, t_list *b, t_cmlist *comm, int count);
void	sort_select_btoa(t_list *a, t_list *b, t_cmlist *comm, int count);
int		devide_rapb(t_list *a, t_list *b, t_cmlist *comm, int count);
int		devide_rbpa(t_list *a, t_list *b, t_cmlist *comm, int count);

void	sort_recur_atob_top(t_list *a, t_list *b, t_cmlist *comm, int count);
void	sort_recur_atob_bottom(t_list *a, t_list *b, t_cmlist *comm, int count);
void	sort_recur_btoa_top(t_list *a, t_list *b, t_cmlist *comm, int count);
void	sort_recur_btoa_bottom(t_list *a, t_list *b, t_cmlist *comm, int count);

void	sort_recur_atob_first(t_list *a, t_list *b, t_cmlist *comm, int count);
void	sort_recur_atob_second(t_list *a, t_list *b, t_cmlist *comm, int count);
void	sort_recur_btoa_last(t_list *a, t_list *b, t_cmlist *comm, int count);

void	free_list(t_list *list);
void	free_command(t_cmlist *list);

#endif
