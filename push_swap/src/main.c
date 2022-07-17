/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:25:26 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_cmlist	*comm;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	comm = malloc(sizeof(t_cmlist));
	init_list(a, b, comm);
	if (argc < 2)
		return (0);
	read_arg(a, argc, argv);
	sort_recur_atob_first(a, b, comm, a->count);
	print_command(comm);
	free_list(a);
	free_list(b);
}

/*
clang++ -std=c++11 random_numbers.cpp -o random_numbers
export ARG=$(./push_swap_tester-main/random_numbers 100 1)
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
 */
