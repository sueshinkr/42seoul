/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/14 18:04:17 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_cmlist	*comm;

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
	if (argc < 2)
		return (0);
	read_arg(a, argc, argv);
	//node_print(a);

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
	if (a->count == 3)
		sort_three_only(a, comm);
	else if (a->count == 5)
		sort_five_only(a, b, comm);
	else
		sort_recur_atob(a, b, comm, a->count);

	print_command(comm);
	//node_print(a);
}

//ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
/*
clang++ -std=c++11 random_numbers.cpp -o random_numbers
export ARG=$(./push_swap_tester-main/random_numbers 100 1)
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | wc -l
 */