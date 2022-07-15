/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:13:12 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/15 19:28:12 by sueshin          ###   ########.fr       */
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
	{
		sort_recur_atob_first(a, b, comm, a->count);
		//sort_recur_atob_top(a, b, comm, a->count);
	}	

	print_command(comm);
	//node_print(a);
}

//ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
/*
clang++ -std=c++11 random_numbers.cpp -o random_numbers

export ARG=$(./push_swap_tester-main/random_numbers 100 1)
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_Mac $ARG
 */


/*
43 77 85 29 57 23 55 30 34 90 31 19 53 50 39 18 65 58 44 76 13 22 49 69 63 59 38 96 7 97 100 46 12 6 48 70 3 1 36 78 87 25 51 4 5 47 88 10 91 92 8 66 45 75 89 27 73 37 83 40 16 26 28 79 81 99 11 62 98 94 21 17 24 60 9 67 35 42 61 86 14 68 80 41 72 15 52 33 56 2 93 20 32 71 82 84 64 95 54 74

88 38 95 40 11 55 16 27 97 26 52 76 4 71 64 65 9 20 80 78 59 94 3 81 14 58 69 57 29 47 43 90 53 92 35 33 36 79 28 85 13 41 68 24 96 6 87 22 34 62 70 63 75 46 60 74 19 67 50 39 82 37 45 86 25 73 8 54 91 72 83 15 93 12 30 2 10 98 84 42 77 32 17 1 7 61 100 89 21 44 99 49 51 5 48 66 31 56 23 18

82 46 39 62 11 98 21 41 63 20 96 7 75 68 18 54 78 23 69 85 70 79 27 66 17 61 50 76 52 58 31 43 88 81 25 30 10 19 86 8 38 64 15 97 6 22 53 48 42 44 36 57 47 56 4 51 94 80 65 77 49 9 100 35 32 83 13 37 84 74 14 95 33 71 73 12 28 24 29 60 72 40 87 1 3 92 59 55 99 67 2 91 16 45 90 34 26 5 93 89

*/
