/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:33:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/18 01:23:16 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
static void	node_print(t_list *a)
{
	t_node	*temp;
	int		idx;

	temp = a->head->next;
	idx = 0;
	ft_printf("::::::::::::::\n");
	while(idx++ < a->count)
	{
		ft_printf("%d\n", temp->num);
		temp = temp->next;
	}
	ft_printf("::::::::::::::\n");
}
*/
static void	check_last(t_list *a, t_list *b)
{
	if (check_dup(a, 1))
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
	if (argc < 1)
		return (0);
	read_arg(a, argc, argv);
	while (1)
	{
		str = get_next_line(1);
		if (!str)
			check_last(a, b);
		else
			select_move(str, a, b);
		free(str);
	}
}

/*
3 2 1 0
0 3 2 1
3 2 1     0
2 3 1     0
1 2 3     0
0 1 2 3
*/