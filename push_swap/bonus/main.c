/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:33:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 19:34:53 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

	while(1)
	{
		str = get_next_line(1);
		if (!str)
		{
			if (check_dup(a))
				printf("OK\n");
			else
				printf("KO\n");
			exit(0);
		}
		free(str);
	}
}
