/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:59:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:47:05 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_command
{
	char				*comm;
	struct s_command	*next;
}	t_command;

typedef struct s_cmlist
{
	t_command	*head;
	t_command	*tail;
}	t_cmlist;

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

t_list	*init_stack_list(void);
void	init_stack(t_list *list, int n);
void	read_arg(t_list *a, int argc, char **argv);
char	**ft_split(char const *str, char c);
void	ft_qsort(int *data, int start, int end);

void	push_stack(t_list *lis1t, int n);
void	pop_stack(t_list *list);
void	func_sa(t_list *a);
void	func_ra(t_list *a);
void	func_rra(t_list *a);
void	func_pa(t_list *a, t_list *b);
void	func_sb(t_list *b);
void	func_rb(t_list *b);
void	func_rrb(t_list *b);
void	func_pb(t_list *b, t_list *a);

void	select_move(char *str, t_list *a, t_list *b);
void	free_list(t_list *list);

#endif
