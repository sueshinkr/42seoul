/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 02:05:50 by sueshin          ###   ########.fr       */
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

//74 39 66 16 43 5 7 57 38 33 75 3 17 28 56 30 31 10 41 61 79 70 76 37 47 20 100 53 50 29 72 60 83 64 88 68 13 24 15 9 4 18 27 90 12 94 59 89 77 80 19 65 84 98 26 69 85 81 91 78 93 46 36 87 49 63 73 32 25 51 11 34 21 45 58 1 97 8 67 48 52 22 55 62 96 2 6 14 42 54 71 95 44 99 35 40 86 82 92 23
