/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:33:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/20 16:44:33 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_last(t_list *a, t_list *b)
{
	if (!b->head->next)
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

	a = init_stack_list();
	b = init_stack_list();
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
