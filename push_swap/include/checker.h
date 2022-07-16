/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:59:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 16:25:11 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

#endif
