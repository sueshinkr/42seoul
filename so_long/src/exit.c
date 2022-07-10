/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:54:38 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 22:35:02 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game_with_map(int flag, t_data *d)
{
	if (flag == 0)
		printf("Empty input map : Error\n");
	else if (flag == 1)
		printf("Not rectangular map : Error\n");
	else if (flag == 2)
		printf("Wrong character input : Error\n");
	else if (flag == 3)
		printf("Wrong wall : Error\n");
	else if (flag == 4)
		printf("Nonvalidated character : Error\n");
	else if (flag == 5)
		printf("Exit Game...\n");
	else if (flag == 6)
		printf("Game Clear!\n");
	else if (flag == 7)
		printf("Don't touch the cow!\n");
	exit(0);
}

int	exit_game_with_red(void)
{
	printf("Exit Game...\n");
	exit(0);
}
