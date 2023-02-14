#include "cub3d.h"

static void	move_left(t_map *map, t_player *p)
{
	if (map->field[(int)(p->posX + p->dirY * p->movsp)][(int)(p->posY)] != '1')
		p->posX += p->dirY * p->movsp;
	if (map->field[(int)(p->posX)][(int)(p->posY + p->dirX * p->movsp)] != '1')
		p->posY += p->dirX * p->movsp;
}

static void	move_right(t_map *map, t_player *p)
{
	if (map->field[(int)(p->posX - p->dirY * p->movsp)][(int)(p->posY)] != '1')
		p->posX -= p->dirY * p->movsp;
	if (map->field[(int)(p->posX)][(int)(p->posY - p->dirX * p->movsp)] != '1')
		p->posY -= p->dirX * p->movsp;
}

int	keypress(int keycode, t_cub *cub)
{
	t_player *p = cub->player;

	if (keycode == 53)
		exit_game_with_map(5);
	else if (keycode == 13)
	{
		if (cub->map->field[(int)(p->posX + p->dirX * p->movsp)][(int)(p->posY)] != '1')
			p->posX += p->dirX * p->movsp;
		if (cub->map->field[(int)(p->posX)][(int)(p->posY + p->dirY * p->movsp)] != '1')
			p->posY += p->dirY * p->movsp;
	}
	else if (keycode == 1)
	{
		if (cub->map->field[(int)(p->posX - p->dirX * p->movsp)][(int)(p->posY)] != '1')
			p->posX -= p->dirX * p->movsp;
		if (cub->map->field[(int)(p->posX)][(int)(p->posY - p->dirY * p->movsp)] != '1')
			p->posY -= p->dirY * p->movsp;
	}
	else if (keycode == 0)
		move_left(cub->map, cub->player);
	else if (keycode == 2)
		move_right(cub->map, cub->player);
	printf("(%f, %f)\n", p->posX, p->posY);
	
	return (0);
}

// w 13 d 2 a 0 s 1 esc 53
