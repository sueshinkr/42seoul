/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/13 17:17:14 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_cmlist	*comm;
	int		idx;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	comm = malloc(sizeof(t_cmlist));
	a->head = malloc(sizeof(t_node));
	a->tail = malloc(sizeof(t_node));
	b->head = malloc(sizeof(t_node));
	b->tail = malloc(sizeof(t_node));
	comm->head = malloc(sizeof(t_command));
	comm->tail = malloc(sizeof(t_command));
	a->count = 0;
	b->count = 0;
	idx = 0;
	if (argc < 2)
		return (0);
	while (argv[++idx])
		init_stack(a, ft_atoi(argv[idx]));
	node_print(a);

/*
	printf("::::sa\n");
	func_s(a);
	node_print(a);

	printf(":::::ra\n");
	func_r(a);
	node_print(a);

	printf(":::::rra\n");
	func_rr(a);
	node_print(a);

	printf(":::::pa\n");
	func_p(b, a);
	node_print(a);
*/
	printf(":::::sort\n");
	if (a->count == 3)
		sort_three(a, comm);
	else if (a->count == 5)
		sort_five(a, b, comm);
	print_command(comm);
	printf("::::::::::::::::::::::::::::::::::::::\n");
	node_print(a);
}
