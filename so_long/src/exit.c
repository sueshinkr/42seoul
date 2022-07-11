/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:54:38 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/11 14:40:40 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game_with_map(int flag)
{
	if (flag == 0)
		ft_putstr_fd("Empty input map : Error\n", 1);
	else if (flag == 1)
		ft_putstr_fd("Not rectangular map : Error\n", 1);
	else if (flag == 2)
		ft_putstr_fd("Wrong character input : Error\n", 1);
	else if (flag == 3)
		ft_putstr_fd("Wrong wall : Error\n", 1);
	else if (flag == 4)
		ft_putstr_fd("Nonvalidated character : Error\n", 1);
	else if (flag == 5)
		ft_putstr_fd("Exit Game...\n", 1);
	else if (flag == 6)
		ft_putstr_fd("Game Clear!\n", 1);
	else if (flag == 7)
		ft_putstr_fd("Don't touch the cow!\n", 1);
	exit(0);
}

int	exit_game_with_red(void)
{
	ft_putstr_fd("Exit Game...\n", 1);
	exit(0);
}
