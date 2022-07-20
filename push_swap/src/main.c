/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:50:44 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_cm		*comm;

	a = init_stack_list();
	b = init_stack_list();
	comm = init_command_list();
	if (argc < 2)
		exit(1);
	read_arg(a, argc, argv);
	sort_recur_atob_first(a, b, comm, a->count);
	print_command(comm);
	free_list(a);
	free_list(b);
	return (0);
}

/*
clang++ -std=c++11 random_numbers.cpp -o random_numbers
export ARG=$(./push_swap_tester-main/random_numbers 100 1)
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
 */
