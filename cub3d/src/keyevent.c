#include "cub3d.h"

int	keypress(int keycode, t_info *d)
{
	(void*)d;
	if (keycode == 53)
		exit_game_with_map(5);
	else if (keycode == 13)
	{
	}
	else if (keycode == 0)
	{
	}
	else if (keycode == 1)
	{
	}
	else if (keycode == 2)
	{
	}
	return (0);
}

// w 13 d 2 a 0 s 1 esc 53