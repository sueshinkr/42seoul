#include "cub3d.h"

void	camera_right(t_player *p)
{
	double bfdirX;
	double bfplaneX;
	
	bfdirX = p->dirX;
	p->dirX = p->dirX * cos(-p->camsp) - p->dirY * sin(-p->camsp);
	p->dirY = bfdirX * sin(-p->camsp) + p->dirY * cos(-p->camsp);
	bfplaneX = p->planeX;
	p->planeX = p->planeX * cos(-p->camsp) - p->planeY * sin(-p->camsp);
	p->planeY = bfplaneX * sin(-p->camsp) + p->planeY * cos(-p->camsp);
}

void	camera_left(t_player *p)
{
	double bfdirX;
	double bfplaneX;
	
	bfdirX = p->dirX;
	p->dirX = p->dirX * cos(p->camsp) - p->dirY * sin(p->camsp);
	p->dirY = bfdirX * sin(p->camsp) + p->dirY * cos(p->camsp);
	bfplaneX = p->planeX;
	p->planeX = p->planeX * cos(p->camsp) - p->planeY * sin(p->camsp);
	p->planeY = bfplaneX * sin(p->camsp) + p->planeY * cos(p->camsp);
}