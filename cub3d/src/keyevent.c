/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:39 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 16:12:27 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keypress(int keycode, t_info *d)
{
	if (keycode == K_ESC)
		exit_game(6);
	else if (keycode == K_W)
		move_up(&d->map, &d->player);
	else if (keycode == K_S)
		move_down(&d->map, &d->player);
	else if (keycode == K_A)
	{
		if (fabs(d->player.dir_x) > fabs(d->player.dir_y))
			move_left(&d->map, &d->player);
		else
			move_right(&d->map, &d->player);
	}
	else if (keycode == K_D)
	{
		if (fabs(d->player.dir_x) > fabs(d->player.dir_y))
			move_right(&d->map, &d->player);
		else
			move_left(&d->map, &d->player);
	}
	if (keycode == K_LEFT)
		camera_left(&d->player);
	else if (keycode == K_RIGHT)
		camera_right(&d->player);
	return (0);
}

//printf("pos(%f, %f)\n", d->player.pos_x, d->player.pos_y);
//printf("dir(%f, %f)\n", d->player.dir_x, d->player.dir_y);
// up 126 down 125
// left 123 right 124
// w 13 d 2 a 0 s 1 esc 53
