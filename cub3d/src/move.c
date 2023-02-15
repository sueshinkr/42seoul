#include "cub3d.h"

void	move_up(t_map *map, t_player *p)
{
	printf("p->posX : %f\n", p->posX);
	if (map->field[(int)(p->posX + p->dirX * p->movsp)][(int)(p->posY)] != '1')
		p->posX += p->dirX * p->movsp;
	if (map->field[(int)(p->posX)][(int)(p->posY + p->dirY * p->movsp)] != '1')
		p->posY += p->dirY * p->movsp;
}

void	move_down(t_map *map, t_player *p)
{
	if (map->field[(int)(p->posX - p->dirX * p->movsp)][(int)(p->posY)] != '1')
		p->posX -= p->dirX * p->movsp;
	if (map->field[(int)(p->posX)][(int)(p->posY - p->dirY * p->movsp)] != '1')
		p->posY -= p->dirY * p->movsp;
}

void	move_left(t_map *map, t_player *p)
{
	if (map->field[(int)(p->posX + p->dirY * p->movsp)][(int)(p->posY)] != '1')
		p->posX += p->dirY * p->movsp;
	if (map->field[(int)(p->posX)][(int)(p->posY + p->dirX * p->movsp)] != '1')
		p->posY += p->dirX * p->movsp;
}
void	move_right(t_map *map, t_player *p)
{
	if (map->field[(int)(p->posX - p->dirY * p->movsp)][(int)(p->posY)] != '1')
		p->posX -= p->dirY * p->movsp;
	if (map->field[(int)(p->posX)][(int)(p->posY - p->dirX * p->movsp)] != '1')
		p->posY -= p->dirX * p->movsp;
}