/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:40:42 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/19 10:45:59 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(int flag)
{
	if (flag == 0)
		printf("Empty input map : Error\n");
	else if (flag == 1)
		printf("Wrong wall : Error\n");
	else if (flag == 2)
		printf("Wrong character input : Error\n");
	else if (flag == 3)
		printf("More than one player : Error\n");
	else if (flag == 4)
		printf("Wrong color range : Error\n");
	else if (flag == 5)
		printf("wrong texture file : Error\n");
	else if (flag == 6)
		printf("Exit Game...\n");
	else if (flag == -1)
		printf("System Error : Error\n");
	exit(0);
}

int	exit_game_with_red(void)
{
	printf("Exit Game...\n");
	exit(0);
}
