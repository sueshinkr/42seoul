/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:33:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/16 16:36:35 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	init_list(a, b);
	if (argc < 1)
		return (0);
	read_arg(a, argc, argv);
}
