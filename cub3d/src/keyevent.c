#include "cub3d.h"

int	keypress(int keycode, t_info *d)
{
	if (keycode == 53)
		exit_game_with_map(5);
	else if (keycode == 13)
		move_up(&d->map, &d->player);
	else if (keycode == 1)
		move_down(&d->map, &d->player);
	else if (keycode == 0)
	{
		if (fabs(d->player.dirX) > fabs(d->player.dirY))
			move_left(&d->map, &d->player);
		else
			move_right(&d->map, &d->player);
	}
	else if (keycode == 2)
	{
		if (fabs(d->player.dirX) > fabs(d->player.dirY))
			move_right(&d->map, &d->player);
		else
			move_left(&d->map, &d->player);
	}
	
	if (keycode == 123)
	{
		camera_left(&d->player);
	}
	else if (keycode == 124)
	{
		camera_right(&d->player);
	}
	printf("pos(%f, %f)\n", d->player.posX, d->player.posY);
	printf("dir(%f, %f)\n", d->player.dirX, d->player.dirY);
	
	return (0);
}

// up 126 down 125
// left 123 right 124
// w 13 d 2 a 0 s 1 esc 53
