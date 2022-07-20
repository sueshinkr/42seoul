/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:33:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 11:24:06 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_last(t_list *a, t_list *b)
{
	if (check_dup(a, 1) && !b->head->next)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(a);
	free_list(b);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*str;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	init_list(a, b);
	if (argc < 2)
		return (0);
	read_arg(a, argc, argv);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			check_last(a, b);
		else
			select_move(str, a, b);
		free(str);
	}
}

/*
30 39 100 85 93 58 45 65 29 79 38 19 20 75 77 12 52 31 21 69 61 13 54 89 67 37 11 51 97 43 25 27 84 68 8 53 15 95 71 80 64 98 26 81 10 4 47 50 44 42 49 56 41 48 76 14 82 62 2 63 90 74 87 70 94 92 72 88 34 57 33 96 22 3 99 5 59 40 18 16 60 1 24 73 83 7 55 17 36 91 23 46 6 28 35 9 66 32 78 86

94 23 12 7 53 17 85 10 79 37 20 25 74 46 47 49 39 59 42 13 86 9 29 43 26 61 35 78 90 6 88 70 66 14 1 89 65 71 100 19 81 38 3 93 69 5 16 75 67 57 99 72 80 82 77 97 64 50 27 60 96 22 84 98 11 8 33 95 92 54 44 18 48 15 62 87 83 63 28 30 52 45 4 34 51 91 31 2 32 55 41 36 76 68 56 73 24 40 21 58

29 74 47 68 22 35 79 13 3 72 20 80 70 58 48 39 94 62 50 28 21 61 12 84 77 38 51 4 42 26 11 15 52 30 54 34 98 36 40 60 75 19 89 93 53 44 97 31 85 18 6 87 69 76 10 66 90 67 27 49 91 73 78 55 100 88 59 32 81 7 43 64 86 57 37 82 17 25 96 8 95 83 5 71 1 2 33 14 92 41 24 45 63 46 23 9 56 16 99 65
*/