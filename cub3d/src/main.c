#include "cub3d.h"

void	calc(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < width)
	{
		double	cameraX = 2 * x / (double)width - 1;
		double	rayDirX = cub->player->DirX + cub->player->planeX * cameraX;
		double	rayDirY = cub->player->DirY + cub->player->planeY * cameraX;
		
		int	mapX = int(posX);
		int	mapY = int(posY);

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX = abs(1 / rayDirX);
		double	deltaDistY = abs(1 / rayDirY);
		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}

		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (cub->map->field[mapX][mapY] > 0)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2 ) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int	lineHeight = (int)(h / perpWallDist);
		int	drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd <= h)
			drawEnd = h - 1;
		
		
	}
}

int	main(int argc, char **argv)
{
	t_info	*d;

	if (argc != 2)
	{
		printf("Wrong input file : Error\n");
		return (0);
	}
	d = malloc(sizeof(t_info));
	init_data(d);
	open_cub(argv[1], d);

	// CHECK
	printf("NO : %s\n", d->cub->north_texture);
	printf("SO : %s\n", d->cub->south_texture);
	printf("WE : %s\n", d->cub->west_texture);
	printf("EA : %s\n", d->cub->east_texture);

	printf("floor : %d %d %d\n", d->cub->floor_color[0], d->cub->floor_color[1], d->cub->floor_color[2]);
	printf("ceiling : %d %d %d\n", d->cub->ceiling_color[0], d->cub->ceiling_color[1], d->cub->ceiling_color[2]);

	printf("Map : \n");

	for (int i = 0; i < d->cub->map->row; i++)
	{
		printf("%s\n", d->cub->map->field[i]);
	}

	mlx_hook(d->win, 17, 0, &exit_game_with_red, NULL);
	mlx_loop_hook(d->mlx, &calc, d->cub);
	mlx_loop(d->mlx);


	return 0;
}
/*
	mlx_hook(d->cub->win, 2, 0, &keypress, data);
	
	mlx_loop_hook(d->cub->mlx, &sel_animation, data);
	mlx_loop(d->cub->mlx);
*/
